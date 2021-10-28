#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include <string.h>


struct my_string {
  int size;
  int capacity;
  char* data;
};
typedef struct my_string  My_string;

MY_STRING my_string_init_default(void){
  My_string* pString = NULL;
  pString = (My_string*)malloc(sizeof(My_string));
  if(pString != NULL) {
    pString->size = 0;
    pString-> capacity = 1;
    pString->data = (char*)malloc(sizeof(char)*pString->capacity);
    if(pString->data == NULL) {
      free(pString);
      pString = NULL;
    }
  }
  return pString;
}

MY_STRING my_string_init_c_string(const char* c_string){
  My_string* pString = NULL;
  pString = (My_string*)malloc(sizeof(My_string));
  if(pString != NULL){
    pString->size = strlen(c_string);
    pString->capacity = strlen(c_string) + 1;
    pString->data = (char*)malloc(sizeof(int)*pString->capacity);
    for(int i = 0; i < sizeof(c_string); i++){
	pString->data[i] = c_string[i];
      }
    if(pString->data == NULL) {
      free(pString);
      pString = NULL;
    }
  }
  return pString;
  
}


int my_string_get_capacity(MY_STRING hMy_string){
  My_string* pString = (My_string*)hMy_string;
  if(pString != NULL)
    return pString->capacity;
  return -1;
}

int my_string_get_size(MY_STRING hMy_string){
  My_string* pString = (My_string*)hMy_string;
  if(pString != NULL)
    return pString->size;
  return -1;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string){
  My_string* rightString = (My_string*)hRight_string;
  My_string* leftString = (My_string*)hLeft_string;
  if(rightString->size > leftString->size){
    return -1;
  }
  else if(rightString->size < leftString->size){
    return 1;
  }
  else {
    return 0;
  }
}

void my_string_destroy(MY_STRING* phMy_string){
  My_string* pString = (My_string*)*phMy_string;
  free(pString->data);
  free(pString);
  *phMy_string = NULL;

}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp){
  My_string* pString = (My_string*)hMy_string;
  char character;
  while((character = fgetc(fp)) != EOF ){
    if(character == ' '){
      break;
    }
    if(pString->size >= pString->capacity){
      char* tmp = (char*)malloc(sizeof(char)*(pString->capacity*2));
      if(tmp == NULL){
	return FAILURE;
	free(tmp);
      }
      for(int i = 0; i < pString->capacity; i++){
	tmp[i] = pString->data[i];
      }
      free(pString->data);
      pString->data = tmp;
      pString->capacity *= 2;
    
      
    }
    pString->data[pString->size] = character;
    pString->size++;
  }
  return SUCCESS;
  
  
}

my_string_insertion(

char char_at(MY_STRING hMy_string, int index){
  My_string* pString = (My_string*)hMy_string;
  return pString->data[index];
}

int get_size(MY_STRING hMy_string){
  My_string* pString = (My_string*)hMy_string;
  return pString->size;
}

int get_capacity(MY_STRING hMy_string){
  My_string* pString = (My_string*)hMy_string;
  return pString->capacity;
}
