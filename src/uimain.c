#include "stdio.h"
#include "tester.h"
#include "tokenizer.h"
#include "history.h"

int main(){
  printf("type something below\n");
  printf("> ");
  char in_len [256];
  fgets(in_len, sizeof(in_len), stdin); 
    
  char** token = tokenize(in_len);
  
  print_tokens(token);
  free_tokens(token);
  
}
