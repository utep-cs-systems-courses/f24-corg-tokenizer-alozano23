#include "stdio.h"
#include "tester.h"
#include "tokenizer.h"
#include "history.h"

int main(){
  printf("type something below\n");
  printf("> ");
  char in_len [256];
  char* user_input = fgets(in_len, sizeof(in_len), stdin);
  char** token = tokenize(user_input);
  print_tokens(token);
  free_tokens(token);
}
