#include <string.h>

#include <stdio.h>

#include <stdlib.h>

#include "tokenizer.h"

#include "history.h"

//#include "tester.h"

/* Initialize the linked list to keep the history. */

List* init_history(){
  struct s_List* history = (struct s_List*)malloc(sizeof(struct s_List));

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
  struct s_Item* histEntry = (struct s_Item*)malloc(sizeof(struct s_Item));
  int len = 0;
  while(string[len] != '\0'){
    len++;
  }
  histEntry->str = malloc(len+1);
  if(histEntry->str == NULL){
    printf("hey, string did not work there");
    free(histEntry);
    return;
  }
  histEntry->str = string;
  histEntry->next = NULL;
  if(list->root == NULL){
    list->root = histEntry;
    histEntry->id = 1;
    //list->root->str = string;
    //list->root->next = NULL;
    return;
  }
  struct s_Item* temp = list->root;
  while(temp->next != NULL){
    temp = temp->next;
  }
  histEntry->id = temp->id+1;
  temp->next = histEntry;
  
  //temp->next->str = string;
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
    free(temp->str);
    free(temp);
    temp = temp->next;
  }
  free(list);
  return;
}

char *get_history(List* list, int id){
  if (list == NULL) return NULL;

  struct s_Item* temp = list->root;

  while (temp != NULL) {

    if (temp->id == id) {

      return temp->str;

    }

    temp = temp->next;

  }

  return NULL;

  
}
