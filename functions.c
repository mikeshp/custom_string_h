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

int can_concatenate(char* destin, char* source)
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
