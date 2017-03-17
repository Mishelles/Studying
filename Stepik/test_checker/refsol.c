#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_TEXT_LEN 1000
#define MAX_TAG_LEN 50


struct TagList{
  char* tag;
  unsigned int line;
  struct Tag *next;
};
typedef struct TagList TagList;

struct TagStack{
  char* tag;
  unsigned int line;
  struct TagStack *prev;
};
typedef struct TagStack TagStack;


TagList *init(char* tag, unsigned int line);
void add_to_list(TagList *head, char* tag, unsigned int line);
void remove_from_list(TagList *head);
unsigned int count_el_in_list(TagList *head);
void push(TagStack *tail, char* tag, unsigned int line);
void pop(TagStack* tail);


int main(int argc, char const *argv[]) {

  char* text = (char*)malloc(MAX_TEXT_LEN*sizeof(char));
  char* tag = (char*)malloc(MAX_TAG_LEN*sizeof(char));
  unsigned int line_count = 1;

  fgets(text, MAX_TEXT_LEN, stdin);

  bool flag = false;
  TagList *head;
  TagStack *tail;
  TagStack *ptr;

  for (unsigned int i = 0; i < MAX_TEXT_LEN; ++i){
    if (text[i]=='\n'){
      line_count++;
    }else if ((flag == false) && (text[i] == '<')){
      flag = true;
    }else if ((flag == true) && (text[i] != '>')){
      tag += text[i];
    }else {
      flag = false;
      if ((strlen(tag)!=0) && (strncmp(tag, "br", 2) != 0) && (strncmp(tag, "hr", 2) != 0)){
        add_to_list(head, tag, line_count);
      }
    }
  }

  for (unsigned int i = 0; i < count(head); ++i){
    if (ptr->tag[0] != '/'){
      push(tail, ptr->tag, ptr->line)
    }else{
      if (strncmp(ptr->tag[1], tail->tag) == 0, strlen(tag)){
        pop(tail);
      }else{
        incorrect_line=tail->line;
        break;
      }
    }
  }
  (incorrect_line>0) ? fprintf(stdout, "wrong %i\n", incorrect_line) : fprintf(stdout, "correct\n");

  return 0;
}
