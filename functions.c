/*
	Other supplemental functions
*/

#include <stdio.h>
#include <stdlib.h>

#include "functions.h"
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

void clear_screen()
{
	printf("\e[2J\e[1;1H");
	fflush(stdout);
}

void switch_display_back()
{
	printf("\e[?1049l");
	fflush(stdout);
}

void switch_display_alternative()
{
	printf("\e[?1049h");
	fflush(stdout);
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

void user_input(char* input_string)
{
	if (fgets(input_string,INPUT_SIZE,stdin) == NULL)
	{
		prompt_error("Wrong input");
		exit(1);
	}

	if (input_string[strlen(input_string)-1] == '\n')
	{
		clear_string(input_string);
	}
	else
	{
		clear_buffer();
	}
}

void prompt_user(const char* prompt)
{
	printf("\e[999;1H");
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

void prompt_hello()
{
	printf("%s\n","Begin the demonstration.");
}

void display_menu_options(const int number)
{
	printf("Choose a function to demonstrate:\n\n");

	for (int i = 1; i <= number; i++)
	{
		printf("\t%2d: %s\n",i,header_lines[i]);
	}

	printf("\n\t%2c: Exit program\n",'Q');
}
