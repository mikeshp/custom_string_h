#include "globals.h"

char  string_1[STRING_SIZE];
char  string_2[STRING_SIZE];
char  string_3[STRING_SIZE];
char  string_4[STRING_SIZE];
char  input_char;
const int error_limit = 5;

const char* header_lines[] =
{
	 "Custom implementation of the <string.h> functions"
	,"strlen() - Return the length of a string"
	,"strcat() - Append one string to the end of another"
	,"strchr() - Return a pointer to the first occurance of a character in a string"
	,"strcmp() - Compare the characters in two strings to determine which string has a higher value"
	,"strcoll() - Compare two strings based on the current locale"
	,"strcpy() - Copy the characters of a string into the memory of another string"
	,"strcspn() - Return the length of a string up to the first occurrence of one of the specified characters"
	,"strerror() - Return a string describing the meaning of an error code"
	,"strncat() - Append N number of characters from a string to the end of another string"
	,"strncmp() - Compare the number of characters in two strings to determine which string has a higher value"
};

char* error_lines[] =
{
	 "Sucess"
	,"Operarion not permitted"
	,"No such file or directory"
	,"No such process"
	,"Interpreted system call"
	,"Input/output error"
};
