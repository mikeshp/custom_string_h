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
//	printf("\n# Custom implementation of the <string.h> functions\n\n");

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
//	printf("\n# strlen() - Return the length of a string\n\n");

	printf("Your string is: %s\n",string_1);
	printf("Its length is %zu characters.\n",strlen(string_1));

	/* Strcat() */

	prompt_header(STRCAT);
//	printf("\n# strcat() - Append one string to the end of another\n\n");

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
		printf("Two strings together: %s\n",
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
//	printf("\n# strchr() - Return a pointer to the first occurance of a character in a string\n\n");

	prompt_user("Enter a character");

	if (scanf("%c",&input_char) != 1)
	{
		prompt_error("Wrong input");
	}
	else
	{
		clear_buffer();
	}

	if (strchr(string_1,input_char) == NULL)
	{
		printf("The character was not found in your string.\n");
	}
	else
	{
		printf("The character \"%c\" is found at position %d.\n",
		input_char,(int)(strlen(string_1) -
		strlen(strchr(string_1,input_char))) + 1);
	}

	/* End of program */

	return 0;
}
