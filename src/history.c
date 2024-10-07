#include <string.h>

#include <stdio.h>

#include <stdlib.h>

#include "tokenizer.h"

#include "history.h"

//#include "tester.h"

/* Initialize the linked list to keep the history. */

List* init_history(){

  struct s_Item* root= (struct s_Item*)calloc(1, sizeof(struct s_Item) );

  struct s_Item* next_node = (struct s_Item*)calloc(1, sizeof(struct s_Item) );

  root->id = 0;

  root->next = next_node;

  struct s_List* list = (struct s_List*)malloc(sizeof(struct s_List) );

  list->root = root;

  return list;

}

void add_history(List* list, char* string){
  return;
}

void print_history(List* list){
  return;
}

void free_history(List* list){
  return;
}

char *get_history(List* list, int id){
  char placeHolder = 'a';
  char* ptr = &placeHolder;
  return ptr;
}
