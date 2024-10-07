#include <string.h>

#include <stdio.h>

#include "tokenizer.h"

#include "malloc.h"

#include "history.h"

//#include "tester.h"

int space_char(char c)

{

  return c == ' '|| c == '\t'|| c == '\0';

}

int non_space_char(char c)

{

  return !(space_char(c));

}

int count_words(char *str)
{
  int alph_char = 0;
  int count = 0;
  while(*str != '\0'){
   if(non_space_char(*str) && alph_char == 0){
     alph_char = 1;
     count++;
   }
   if(space_char(*str) && alph_char == 1){
     alph_char = 0;
   }
   str++;
  }
  return count;
}

char *word_start(char *str)
{
  if(non_space_char(*str)){return str;}
  if(space_char(*str) && *str =='\0'){
    return '\0';
  }
  
  return word_start(str+1);
}

char *word_terminator(char *word)
{
  if(space_char(*word) ){ return word;}
  return word_terminator(word+1);
}

char *copy_str(char* inStr, short len)
{
  char* word_token = (char*) malloc( sizeof(char) *(len+1) );
  char* tok_start = word_token;

  for(int i = 0; i < len; i++){
    if(non_space_char(*inStr)){
      *word_token = *inStr;
      word_token++;
    }
    inStr++;
  }
  *word_token = '\0';
  return tok_start;
}
char** tokenize(char* str)
{
  int num_words = count_words(str);
  char**  arr_ptr =(char**)malloc((num_words)*sizeof(char*));
  for(int i = 0; i < num_words; i++){
    char* start = word_start(str);
    char* end = word_terminator(str);
    arr_ptr[i] = copy_str(start, end-start);
    //str = end++;
    str = end;			   
  }
  return arr_ptr;
}

void print_tokens(char **tokens)
{
  char** start =  tokens;
  while(*start){
    printf("%s ", *start);
    *start++;
    
  }
  tokens = start;
  free(start);
  return;
}

void free_tokens(char **tokens)
{
  if(tokens == NULL){return;}
  char** ptr = tokens;
  while(*ptr){
    free(*ptr);
    ptr++;
  }
  free(tokens);
  return;
}

