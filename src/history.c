#include <string.h>

#include <stdio.h>

#include <stdlib.h>

#include "tokenizer.h"

#include "history.h"

//#include "tester.h"

/* Initialize the linked list to keep the history. */

List* init_history(){
  struct s_List* history = (struct s_List*)malloc(sizeof(struct s_List*));

  if(history == NULL){
    printf("history not initialized by init_history() ");
    return NULL;
  }
  history->root = NULL;
  return history;
}

void add_history(List* list, char* string){
  if(list == NULL){
    printf("No history created");
    return;
  }
  if(string == NULL){
    printf("No viable string found!");
    return;
  }
  struct s_Item* histEntry = (struct s_Item*)malloc(sizeof(struct s_Item*));

  if(list->root == NULL){
    list->root = histEntry;
    list->root->str = string;
    list->root->next = NULL;
    return;
  }
  struct s_Item* temp = list->root;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = histEntry;
  temp->next->str = string;
  return;
}

void print_history(List* list){
  if(list == NULL){
    printf("History not found");
    return;
  }
  struct s_Item* temp = list->root;
  while(temp != NULL){
    printf("%d. %s\n", temp->id, temp->str);
    temp = temp->next;
  }
  return;
}

void free_history(List* list){
  if (list == NULL)return;
  struct s_Item* temp = list->root;

  while(temp != NULL){
    free(temp);
    temp = temp->next;
  }
  free(list);
  return;
}

char *get_history(List* list, int id){
  char placeHolder = 'a';
  char* ptr = &placeHolder;
  return ptr;
}
