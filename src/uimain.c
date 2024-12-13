#include "stdio.h"
#include "tester.h"
#include "tokenizer.h"
#include "history.h"

int main(){
  struct s_List* list = init_history();
 start:
  printf("type something below\n");
  printf("> ");
  char in_len [256];
  fgets(in_len, sizeof(in_len), stdin);
  in_len[strcspn(in_len, "\n")] = '\0';
  char* string = strdup(in_len);
  add_history(list, string);  
  char** token = tokenize(in_len);
    
  print_tokens(token);
  free_tokens(token);
  goto print;
  
 print:
  printf("Do you want to print the history?\n");
  fgets(in_len, sizeof(in_len), stdin);
  in_len[strcspn(in_len, "\n")] = '\0'; 
  if( in_len[0] =='y' || in_len[0] =='Y'){
    print_history(list);
    goto quit;
  }
  else if(in_len[0] =='N'|| in_len[0] == 'n'){
    goto quit;
  }else{
    printf("misinput. Try Again!\n");
    goto print;
  }
 quit:
  printf("would you like to quit?\n");
  fgets(in_len, sizeof(in_len), stdin);
  in_len[strcspn(in_len, "\n")] = '\0'; 
  if(in_len[0] == 'y' || in_len[0] =='Y' ){
    free_history(list);
    goto end;
  }
  goto start;

 end:
  printf("Goodbye\n");
  
}
