#ifndef GLOBALS_H
#define GLOBALS_H

#define STRING_SIZE 512

enum Header
{
	 HEADER
	,STRLEN
	,STRCAT
	,STRCHR
	,STRCMP
	,STRCOLL
	,STRCPY
	,STRCSPN
	,STRERROR
};

extern char  string_1[STRING_SIZE];
extern char  string_2[STRING_SIZE];
extern char  string_3[STRING_SIZE];
extern char  string_4[STRING_SIZE];
extern char  input_char;
extern const char* header_lines[];
extern char* error_lines[];
extern const int error_limit;

#endif
