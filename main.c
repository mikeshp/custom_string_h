/*
	Main program logic shared among both standard and custom main files.
	Everything must lead to equivalent results both using
	standard and custom string.h headers.
*/

#include <stdio.h>

#include "globals.h"
#include "functions.h"

#ifndef CUSTOM_LIB
	#include <string.h>
#else
	#include "my_string.h"
	#include "my_string_names.h"
#endif

int main()
{
	/* Prompt user for the strings */

	prompt_header(HEADER);
	prompt_user("Enter a string");

	if (fgets(string_1,sizeof(string_1),stdin) == NULL)
	{
		prompt_error("Wrong input");
	}

	if (string_1[strlen(string_1) - 1] == '\n')
	{
		clear_string(string_1);
	}
	else
	{
		clear_buffer();
	}

	/* Strlen() */

	prompt_header(STRLEN);

	printf("Your string is: \"%s\"\n",string_1);
	printf("Its length is %zu characters.\n",strlen(string_1));

	/* Strcat() */

	prompt_header(STRCAT);
	prompt_user("Enter a second string");

	if (fgets(string_2,sizeof(string_2),stdin) == NULL)
	{
		prompt_error("Wrong input");
	}

	if (string_2[strlen(string_2) - 1] == '\n')
	{
		clear_string(string_2);
	}
	else
	{
		clear_buffer();
	}

	if (can_concatenate(string_1,string_2))
	{
		// keep string_1 intact after concatenation
//		string_3 = string_1;

		printf("Two strings together: \"%s\"\n",
		strcat(string_1,string_2));

		printf("Concatenated string's length is %zu.\n",
		strlen(string_1));
	}
	else
	{
		prompt_error("Buffer too low");
	}

	/* Strchr() */

	prompt_header(STRCHR);
	prompt_user("Enter a character");

	if (scanf("%c",&input_char) != 1)
	{
		prompt_error("Wrong input");
	}
	else
	{
		clear_buffer();
	}

	if (strchr(string_1,input_char) == NULL
	&&  strchr(string_2,input_char) == NULL)
	{
		printf("The character was not found in your strings.\n");
	}
	else
	{
		if (strchr(string_1,input_char) != NULL)
		{
			prompt_char_found(string_1,input_char,"first");
		}

		if (strchr(string_2,input_char) != NULL)
		{
			prompt_char_found(string_2,input_char,"second");
		}
	}

	/* Strcmp() */

	prompt_header(STRCMP);

	if (strcmp(string_1,string_2) == 0)
	{
		printf("Both strings are alphabetically equal.\n");
	}
	else if (strcmp(string_1,string_2) > 0)
	{
		printf("First string is greater than the second.\n");
		prompt_strings_in_order(string_1,string_2);
	}
	else if (strcmp(string_1,string_2) < 0)
	{
		printf("Second string is greater than the first.\n");
		prompt_strings_in_order(string_1,string_2);
	}
	else
	{
		prompt_error("Wrong comparison");
	}

	/* End of program */

	return 0;
}
