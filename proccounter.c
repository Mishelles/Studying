/***********************************************************
******A program to count all descendants of process in Linux
******It parses /proc/stat to find information about process
******and creates a tree of processes using single linked list
------------------------------------------------------------
******Created by Mikhail Sergeenkov on 20th of February, 2016
******sergeenkov.michael@gmail.com
******github.com/Mishelles
************************************************************/


#include <unistd.h>
#include <sys/types.h>
#include <ctype.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#define BUF 40

struct Proc{
  int pid;
  struct Proc* next;
};

struct Proc *proc_tree_head;
struct Proc *proc_family_head;

struct Proc * init(int a);
void addToFamily(int number);
void addToTree(int number);
void Procprint();
int counter();
int procParser(int pid);
int isDescendant(int pid1, int pid2);
void getPidsFromProc();
void pedigreeBuilder(int num);
int counterFamily();
void ProcTreeprint();

int main(int argc, char const *argv[]) {
  if (argc<2){
    printf("Ошибка: Введите pid\n");
    exit(1);
  }
  int pid=atoi(argv[1]);
  proc_family_head=init(pid);
  proc_tree_head=init(1);
  getPidsFromProc();
  pedigreeBuilder(pid);
  struct Proc *ptr=proc_family_head->next;
  while(ptr!=NULL){
    pedigreeBuilder(ptr->pid);
    ptr=ptr->next;
  }
  //printf("%i\n", proc_family_head->pid);
  //Procprint();
  printf("%d\n", counterFamily());
  return 0;
}

void pedigreeBuilder(int num){
  struct Proc *ptr=proc_tree_head;
  while(ptr!=NULL){
    if(isDescendant(num, ptr->pid)){
      addToFamily(ptr->pid);
    }
    ptr=ptr->next;
  }
  return;
}


int procParser(int pid){
  int ppid;
  int i;
  char path[20];
  int fd;
  char str[BUF];
  sprintf(path, "/proc/%i/stat", pid);
  fd=open(path, O_RDONLY);
  if(read(fd, str, BUF)==-1){
    printf("Something went wrong\n");
    exit(1);
  }
  close(fd);
  char* parsed;
  parsed=strtok(str, " ");
  for (i=0; i<3; ++i){
    parsed=strtok(NULL, " ");
  }
  ppid=atoi(parsed);
  return ppid;
}

int isDescendant(int pid1, int pid2){
  int ppid=procParser(pid2);
  if (ppid==pid1)
    return 1;
  else
    return 0;
}

void getPidsFromProc(){
  DIR *dir;
    struct dirent *entry;

    dir = opendir("/proc");
    if (!dir) {
        perror("diropen");
        exit(1);
    };

    while ( (entry = readdir(dir)) != NULL) {
      if (atoi(entry->d_name)>1){
        addToTree(atoi(entry->d_name));
      }
    }

    closedir(dir);
  return;
}

int counter(){
  int k=0;
  struct Proc* ptr=proc_tree_head;
  while(ptr->next!=NULL){
    ++k;
    ptr=ptr->next;
  }
  return k;
}

struct Proc * init(int a) // а- значение первого узла
{
  struct Proc *proc;
  // выделение памяти под корень списка
  proc = (struct Proc*)malloc(sizeof(struct Proc));
  proc->pid = a;
  proc->next = NULL; // это последний узел списка
  return(proc);
}

void addToTree(int number)
{
  struct Proc *temp, *ptr;
  temp = (struct Proc*)malloc(sizeof(struct Proc));
  temp->pid=number;
  temp->next=NULL;
  ptr=proc_tree_head;
  while(ptr->next!=NULL){
    ptr=ptr->next;
  }
  ptr->next=temp;
  return;
}

void addToFamily(int number){
  struct Proc *temp, *ptr;
  temp = (struct Proc*)malloc(sizeof(struct Proc));
  temp->pid=number;
  temp->next=NULL;
  ptr=proc_family_head;
  while(ptr->next!=NULL){
    ptr=ptr->next;
  }
  ptr->next=temp;
  return;
}

void Procprint()
{
  struct Proc *p;
  p = proc_family_head;
  do {
    printf("%d\n", p->pid); // вывод значения элемента p
    p = p->next; // переход к следующему узлу
  } while (p != NULL);
}

int counterFamily(){
  int k=0;
  struct Proc* ptr=proc_family_head;
  while(ptr!=NULL){
    ++k;
    ptr=ptr->next;
  }
  return k;
}

void ProcTreeprint()
{
  struct Proc *p;
  p = proc_tree_head;
  do {
    printf("%d\n", p->pid); // вывод значения элемента p
    p = p->next; // переход к следующему узлу
  } while (p != NULL);
}
