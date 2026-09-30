/*
	Other supplemental functions
*/

#include <stdio.h>
#include "globals.h"

#ifndef CUSTOM_LIB
	#include <string.h>
#else
	#include "my_string.h"
	#include "my_string_names.h"
#endif

void print_substring(const char* prefix, const char* string, size_t number)
{
	if (number > strlen(string))
	{
		number = strlen(string);
	}

	printf("%s: \"",prefix);
	for (int i = 0; i < (int) number; i++)
	{
		printf("%c",string[i]);
	}
	printf("\"\n");
}

void prompt_char_found(const char* str, const char chr, const char* arg)
{
	printf(
	"The character \"%c\" was found in the %s string at position %d.\n",
	chr,arg,((int)strlen(str) - (int)strlen(strchr(str,chr))) + 1);
}

void prompt_strings_in_order(const char* str1, const char* str2)
{
	printf("Two strings in alphabetical order:\n");
	printf("\"%s\", \"%s\"\n",
	strcmp(str1,str2) > 0 ? str2 : str1,
	strcmp(str1,str2) > 0 ? str1 : str2);
}

void prompt_header(enum Header header)
{
	printf("\n# %s\n\n",header_lines[header]);
}

void clear_string(char* string)
{
	int c = 0;
	while (string[c] != '\0' && string[c] != EOF)
	{
		if (string[c] == '\n')
		{
			string[c] = '\0';
			break;
		}

		c++;
	}
}

void clear_buffer()
{
	int clear;
	while ((clear = getchar()) != '\n' && clear != EOF);
}

int can_copy(const char* destin, const char* source)
{
	if (strlen(destin) < strlen(source) + 1)
	{
		return 0;
	}

	return 1;
}

int can_concatenate(const char* destin, const char* source)
{
	if ((strlen(destin) + strlen(source) + 1) > STRING_SIZE)
	{
		return 0;
	}

	return 1;
}

void prompt_user(const char* prompt)
{
	printf("%s:\n",prompt);
	printf("> ");
}

void prompt_error(const char* prompt)
{
	printf("ERROR: %s.\n",prompt);
}

void prompt_pause()
{
	printf("\n");

	int user_input;
	while (1)
	{
		printf("Press <Enter> to continue... ");
		user_input = getchar();

		if (user_input == '\n')
		{
			break;
		}

		clear_buffer();
	}
}

void prompt_goodbye()
{
	printf("\n%s\n","End of demonstration.");
}
