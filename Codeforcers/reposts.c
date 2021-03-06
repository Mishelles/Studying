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
#include <ctype.h>
#define NAME_LEN 24
#define BUF_SIZE 60

struct Repost{
  char reposter[NAME_LEN];
  char author[NAME_LEN];
  struct Repost* parent;
};
typedef struct Repost Repost;

int counter(Repost *leaf, Repost *tree_head);
int strComparator(char str1[NAME_LEN], char str2[NAME_LEN]);
void upCase(char str[NAME_LEN]);

int main(int argc, char const *argv[]) {
  int n; /*number of reposts*/
  int max_repost_chain=0;
  int k;
  scanf("%d\n", &n);
  char buf_str[BUF_SIZE];
  char *token; /*will be used in strtok*/
  Repost *reposts_array=(Repost*)malloc(n*sizeof(Repost)); /*In this array we will store all reposts*/

  /*Create array*/
  for (int i = 0; i < n; i++) {
    fgets(buf_str, BUF_SIZE, stdin);
    token=strtok(buf_str, " ");
    strncpy(reposts_array[i].reposter, token, NAME_LEN);
    token=strtok(NULL, " ");
    token=strtok(NULL, " ");
    strncpy(reposts_array[i].author, token, NAME_LEN);
    reposts_array[i].parent=NULL;
    upCase(reposts_array[i].reposter);
    upCase(reposts_array[i].author);
    memset(buf_str, 0, BUF_SIZE);
    memset(token, 0, strlen(token));
  }

  Repost* tree_head=(Repost*)malloc(sizeof(Repost));
  strncpy(tree_head->reposter, "POLYCARP", NAME_LEN);
  tree_head->parent=NULL;
  /*Create tree*/
  for (int i = 0; i < n; i++){
    if(strComparator(tree_head->reposter, reposts_array[i].author)==0){
      for (int j = 0; j < n; j++){
        if (strComparator(reposts_array[i].author, reposts_array[j].reposter)==1){
          reposts_array[i].parent=&reposts_array[j];
          break;
        }
      }
    }else{
      reposts_array[i].parent=tree_head;
    }
  }
  /*tree traversal*/
  for (int i = 0; i < n; i++){
    k=counter(&reposts_array[i], tree_head);
    if(k>max_repost_chain){
      max_repost_chain=k;
    }
  }
  printf("%d\n", max_repost_chain);
  free(reposts_array);
  return 0;
}

int counter(Repost *leaf, Repost *tree_head){
  Repost *ptr=leaf;
  int k=0;
  while(ptr->parent!=NULL){
    ++k;
    ptr=ptr->parent;
  }
  if (ptr->reposter==tree_head->reposter){
    ++k;
    return k;
  }else{
    return 0;
  }
}

int strComparator(char str1[NAME_LEN], char str2[NAME_LEN]){
  int flag=1;
  for (int i = 0; i < NAME_LEN; i++) {
    if ((str1[i]=='\0')||(str2[i]=='\0')){
      break;
    }
    if(str1[i]!=str2[i]){
      flag=0;
      break;
    }
  }
    return flag;
}

void upCase(char str[NAME_LEN]){
  for (int i = 0; i < NAME_LEN; i++){
    if(str[i]=='\0'){
      break;
    }else{
      str[i]=toupper(str[i]);
    }
  }
  return;
}
