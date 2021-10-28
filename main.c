#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

int main(int argc, char* argv[]){

  MY_STRING hNewString = NULL;
  hNewString = my_string_init_default();

  if(hNewString == NULL){
    exit(1);
  }
  FILE *pFile = fopen("simple.txt", "r");

  if(pFile == NULL){
    printf("file didnt open");
    exit(1);
  }

  my_string_extraction(hNewString, pFile);

  my_string_extraction(hNewString, pFile);

  for(int i = 0; i < get_size(hNewString); i++){
    printf("%c", char_at(hNewString, i));
  }
  printf("\n");
  

  fclose(pFile);

  my_string_destroy(&hNewString);

  
   return 0;
}
