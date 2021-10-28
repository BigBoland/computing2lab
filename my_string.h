#include "status.h"

typedef void* MY_STRING;
//Precondition: None
//Postcondition: Allocate space for a string object that represents the empty
//string. The string will have capacity 7 and size 0 by default. A copy of
// the address of the opaque object will be returned on success and NULL on
// failure.
MY_STRING my_string_init_default(void);

// precondition: phMy_string holds the address of a valid handle to a MY_STRING
// object
//Postcondition: the memory used for the mY_STRING object has to be reclaimed
// by the system and the handle referred to by the pointer phMy_string has
// been set to NULL

void my_string_destroy(MY_STRING* phMy_string);

//Precondition: c-string is a valid null terminated c-string.
//Postcondition Allocate space for a string object that represents a string
// with the same value as the given c-string. The capacity of the string
// object will be set to be one greater than is required to hold the string.
// As an example, the string "the" would set capacity at 4 instead of 3. A
// copy of the address of the opaque object will be returned on success and
// NULL on failure.

MY_STRING my_string_init_c_string(const char* c_string);

//Precondition: hMy_string is he handle of a valid object
//Postcondition: returns an int of the object capacity
int my_string_get_capacity(MY_STRING hMy_string);

//precondition: hMy_string is the handle of a valid object
//Postcondition: Returns a copy of the objects size
int my_string_get_size(MY_STRING hMy_string);

//Precondition: hLeft_string and hRight_string are valid objects
//Postcondition: returns an integer less than zero if the left string
//is smaller than the right. returns 0 if they are equal and 1 if left
//string is bigger

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string);

//Precondition: hMy_string is the handle to a valid My_string object.
//Postcondition: hMy_string will be the handle of a string object that contains
// the next string from the file stream fp according to the following rules
// 1) Leading whitespace will be ignored.
// 2) All characters will be added to the string until a stopping condition
// is met
// 3) a stopping condition is either 2 white spaces in a row, or end of file
// Function will return SUCCESS if a non-empty string is read successfully.

Status my_string_extraction(MY_STRING hMy_string, FILE* fp);

// precon: hMy_string is a valid object
//postcon: writes the characters contained in the string to file steam
//returns success or failure

Status my_string_insertion(MY_STRING hMy_string, FILE* fp);

char char_at(MY_STRING hMy_string, int index);

int get_size(MY_STRING hMy_string);

int get_capacity(MY_STRING hMy_string);



