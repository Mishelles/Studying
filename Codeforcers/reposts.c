/***********************************************************
******Preparation for VK Cup. Task #1. Reposts.
------------------------------------------------------------
******Program returns max repost-chain length
------------------------------------------------------------
******Created by Mikhail Sergeenkov on the 2th of March, 2017
******sergeenkov.michael@gmail.com
******github.com/Mishelles
************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LEN 24
#define BUF_SIZE 60

typedef struct Repost Repost;
struct Repost{
  char reposter[NAME_LEN];
  char author[NAME_LEN];
};
typedef struct List List;
struct List{
  char name[NAME_LEN];
  List *next;
};

int counter(List *head);
List *init(char name[NAME_LEN]);
void push(List* head, char name[NAME_LEN]);
void printList(List* head);

int main(int argc, char const *argv[]) {
  int n; /*name of reposts*/
  scanf("%d\n", &n);
  char buf_str[BUF_SIZE];
  char *token; /*will be used in strtok*/
  Repost *reposts_array=(Repost*)malloc(n*sizeof(Repost)); /*In this array we will store all reposts*/
  for (int i = 0; i < n; i++) {
    fgets(buf_str, BUF_SIZE, stdin);
    token=strtok(buf_str, " ");
    strncpy(reposts_array[i].reposter, token, NAME_LEN);
    token=strtok(NULL, " ");
    token=strtok(NULL, " ");
    strncpy(reposts_array[i].author, token, NAME_LEN);
    memset(buf_str, 0, BUF_SIZE);
    memset(token, 0, strlen(token));
  }
  /*Debug*/
  for (int i = 0; i < n; i++){
    printf("Struct %i:\n", i);
    printf("reposter:%s\n", reposts_array[i].reposter);
    printf("author:%s", reposts_array[i].author);
    printf("------------------------\n");
  }
  List *head=init("Polycarp");
  for (int i = 0; i < n; i++) {
    push(head, reposts_array[i].reposter);
  }
  printList(head);
  free(head);
  free(reposts_array);
  return 0;
}

int counter(List *head){
  int k=0;
  List* ptr=head;
  while(ptr->next!=NULL){
    ++k;
    ptr=ptr->next;
  }
  return k;
}

List *init(char name[NAME_LEN]) // а- значение первого узла
{
  List *tmp;
  // выделение памяти под корень списка
  tmp = (List*)malloc(sizeof(List));
  strncpy(tmp->name, name, NAME_LEN);
  tmp->next = NULL; // это последний узел списка
  return(tmp);
}

void push(List* head, char name[NAME_LEN])
{
  List *tmp, *ptr;
  tmp = (List*)malloc(sizeof(List));
  strncpy(tmp->name, name, NAME_LEN);
  tmp->next=NULL;
  ptr=head;
  while(ptr->next!=NULL){
    ptr=ptr->next;
  }
  ptr->next=tmp;
  return;
}

void printList(List* head)
{
  List* ptr=head;
  while(ptr->next!=NULL){
    printf("%s\n", ptr->name);
    ptr=ptr->next;
  }
  return;
}
