/*
	Substitute the standard <string.h> function names
	With names of my custom functions
*/

#ifndef MY_STRING_NAMES_H
#define MY_STRING_NAMES_H

#define strlen(x) my_strlen(x)
#define strcat(x,y) my_strcat(x,y)
#define strchr(x,y) my_strchr(x,y)
#define strcmp(x,y) my_strcmp(x,y)
#define strcpy(x,y) my_strcpy(x,y)

#endif
