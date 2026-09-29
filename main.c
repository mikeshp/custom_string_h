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
		return 1;
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

//	prompt_pause();
	prompt_header(STRLEN);

	printf("Your string is: \"%s\"\n",string_1);
	printf("Its length is %zu characters.\n",strlen(string_1));

	/* Strcat() */

	prompt_pause();
	prompt_header(STRCAT);
	prompt_user("Enter a second string");

	if (fgets(string_2,sizeof(string_2),stdin) == NULL)
	{
		prompt_error("Wrong input");
		return 1;
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
		// keep string_1 intact after demonstration
		strcpy(string_3,string_1);

		printf("Two strings together: \"%s\"\n",
		strcat(string_3,string_2));

		printf("Concatenated string's length is %zu.\n",
		strlen(string_3));
	}
	else
	{
		prompt_error("Buffer too low");
		return 1;
	}

	/* Strchr() */

	prompt_pause();
	prompt_header(STRCHR);
	prompt_user("Enter a character");

	if (scanf("%c",&input_char) != 1)
	{
		prompt_error("Wrong input");
		return 1;
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

	prompt_pause();
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
		return 1;
	}

	/* Strcoll() */

	prompt_pause();
	prompt_header(STRCOLL);

	// Add later

	/* Strcpy() */

	prompt_pause();
	prompt_header(STRCPY);

	printf("Attempt to make a copy of the first string in the third...");

	if (can_copy(string_3,string_1))
	{
		printf("Success!\n");
		printf("Third string (copied from the first): \"%s\"\n",
		strcpy(string_3,string_1));
	}
	else
	{
		prompt_error("Buffer too low");
		return 1;
	}

	/* Strcspn() */

	prompt_pause();
	prompt_header(STRCSPN);

	printf("Attempt to concatenate the second string into the third...");

	if (can_concatenate(string_3,string_2))
	{
		printf("Success!\n");
		printf("The concatenated string is now: \"%s\"\n",
		strcat(string_3,string_2));
	}
	else
	{
		prompt_error("Buffer too low");
		return 1;
	}

	prompt_user("Enter a sequence of characters to find in the string");

	if (fgets(string_4,sizeof(string_4),stdin) == NULL)
	{
		prompt_error("Wrong input");
		return 1;
	}

	if (string_4[strlen(string_4) - 1] == '\n')
	{
		clear_string(string_4);
	}
	else
	{
		clear_buffer();
	}

	if (strcspn(string_3,string_4) == strlen(string_3))
	{
		printf("None of the characters were found in the string!\n");
	}
	else
	{
		printf("Length before the character \"%c\" is found is: %zu.\n",
		string_3[strcspn(string_3,string_4)],strcspn(string_3,string_4));
	}

	/* Strerror() */

	prompt_pause();
	prompt_header(STRERROR);

	printf("Examples of what strerror() returns with custom errnum.\n");
	printf("Locale will be ignored since it's beyond the scope of this project.\n");
	printf("Any indice beyond 0 - %d range will be interpreted as \"unknown\":\n",error_limit);

	for (int i = -2; i <= (error_limit + 2); i++)
	{
		printf("\t%4d -> %s\n",i,strerror(i));
	}

	/* Strncat() */

	prompt_pause();
	prompt_header(STRNCAT);

	/* End of program */

	prompt_goodbye();
	return 0;
}
