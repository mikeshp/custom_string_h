/*
	My own implementation of the standard <String.h> functions.
	Names must follow my_[standard_name] pattern.
*/

#ifndef MY_STRING_H
#define MY_STRING_H

size_t my_strlen(const char*);
char*  my_strcat(char*,const char*);
char*  my_strchr(const char*,const int);
int    my_strcmp(const char*,const char*);
char*  my_strcpy(char*, const char*);

#endif
