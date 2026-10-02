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
int    my_strncmp(const char*,const char*,size_t);
char*  my_strcpy(char*, const char*);
size_t my_strcspn(const char*,const char*);
char*  my_strerror(int);
char*  my_strncat(char*,const char*,size_t);
char*  my_strpbrk(const char*,const char*);

#endif
