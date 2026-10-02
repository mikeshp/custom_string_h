/*
	Main program logic shared among both standard and custom main files.
	Everything must lead to equivalent results both using
	standard and custom string.h headers.
*/

#include <stdio.h>
#include <stdlib.h>

#include "globals.h"
#include "functions.h"
#include "demo_function.h"

#ifndef CUSTOM_LIB
	#include <string.h>
#else
	#include "my_string.h"
	#include "my_string_names.h"
#endif

int main()
{
	char  user_select[INPUT_SIZE];
	const int punks_not_dead = 1;
//	const int options_list   = 11;

	prompt_hello();
	switch_display_alternative();

	/* Main Menu */

	while (punks_not_dead)
	{
		clear_screen();
		prompt_header(HEADER);
		display_menu_options(NUMBER-1);

		prompt_user("Enter 1-10 or Q");
		user_input(user_select);

		if (user_select[0] == 'Q' || user_select[0] == 'q')
		{
			break;
		}

		switch(atoi(user_select))
		{
			case 1 ... NUMBER-1:
				demo_function(atoi(user_select));
				prompt_pause();
				break;
			default:
				break;
		}
	}

	/* Prompt user for the strings */
//
//	prompt_header(HEADER);
//	prompt_user("Enter a string");
//
//	if (fgets(string_1,sizeof(string_1),stdin) == NULL)
//	{
//		prompt_error("Wrong input");
//		return 1;
//	}
//
//	if (string_1[strlen(string_1) - 1] == '\n')
//	{
//		clear_string(string_1);
//	}
//	else
//	{
//		clear_buffer();
//	}

	/* Strlen() */

//	prompt_header(STRLEN);
//
//	printf("Your string is: \"%s\"\n",string_1);
//	printf("Its length is %zu characters.\n",strlen(string_1));

	/* Strcat() */

//	prompt_pause();
//	prompt_header(STRCAT);
//	prompt_user("Enter a second string");
//
//	if (fgets(string_2,sizeof(string_2),stdin) == NULL)
//	{
//		prompt_error("Wrong input");
//		return 1;
//	}
//
//	if (string_2[strlen(string_2) - 1] == '\n')
//	{
//		clear_string(string_2);
//	}
//	else
//	{
//		clear_buffer();
//	}
//
//	if (can_concatenate(string_1,string_2))
//	{
//		// keep string_1 intact after demonstration
//		strcpy(string_3,string_1);
//
//		printf("Two strings together: \"%s\"\n",
//		strcat(string_3,string_2));
//
//		printf("Concatenated string's length is %zu.\n",
//		strlen(string_3));
//	}
//	else
//	{
//		prompt_error("Buffer too low");
//		return 1;
//	}

	/* Strchr() */

//	prompt_pause();
//	prompt_header(STRCHR);
//	prompt_user("Enter a character");
//
//	if (scanf("%c",&input_char) != 1)
//	{
//		prompt_error("Wrong input");
//		return 1;
//	}
//	else
//	{
//		clear_buffer();
//	}
//
//	if (strchr(string_1,input_char) == NULL
//	&&  strchr(string_2,input_char) == NULL)
//	{
//		printf("The character was not found in your strings.\n");
//	}
//	else
//	{
//		if (strchr(string_1,input_char) != NULL)
//		{
//			prompt_char_found(string_1,input_char,"first");
//		}
//
//		if (strchr(string_2,input_char) != NULL)
//		{
//			prompt_char_found(string_2,input_char,"second");
//		}
//	}

	/* Strcmp() */

//	prompt_pause();
//	prompt_header(STRCMP);
//
//	if (strcmp(string_1,string_2) == 0)
//	{
//		printf("Both strings are alphabetically equal.\n");
//	}
//	else if (strcmp(string_1,string_2) > 0)
//	{
//		printf("First string is greater than the second.\n");
//		prompt_strings_in_order(string_1,string_2);
//	}
//	else if (strcmp(string_1,string_2) < 0)
//	{
//		printf("Second string is greater than the first.\n");
//		prompt_strings_in_order(string_1,string_2);
//	}
//	else
//	{
//		prompt_error("Wrong comparison");
//		return 1;
//	}

	/* Strcoll() */

//	prompt_pause();
//	prompt_header(STRCOLL);

	// Add later

	/* Strcpy() */

//	prompt_pause();
//	prompt_header(STRCPY);
//
//	printf("Attempt to make a copy of the first string in the third...");
//
//	if (can_copy(string_3,string_1))
//	{
//		printf("Success!\n");
//		printf("Third string (copied from the first): \"%s\"\n",
//		strcpy(string_3,string_1));
//	}
//	else
//	{
//		prompt_error("Buffer too low");
//		return 1;
//	}

	/* Strcspn() */

//	prompt_pause();
//	prompt_header(STRCSPN);
//
//	printf("Attempt to concatenate the second string into the third...");
//
//	if (can_concatenate(string_3,string_2))
//	{
//		printf("Success!\n");
//		printf("The concatenated string is now: \"%s\"\n",
//		strcat(string_3,string_2));
//	}
//	else
//	{
//		prompt_error("Buffer too low");
//		return 1;
//	}
//
//	prompt_user("Enter a sequence of characters to find in the string");
//
//	if (fgets(string_4,sizeof(string_4),stdin) == NULL)
//	{
//		prompt_error("Wrong input");
//		return 1;
//	}
//
//	if (string_4[strlen(string_4) - 1] == '\n')
//	{
//		clear_string(string_4);
//	}
//	else
//	{
//		clear_buffer();
//	}
//
//	if (strcspn(string_3,string_4) == strlen(string_3))
//	{
//		printf("None of the characters were found in the string!\n");
//	}
//	else
//	{
//		printf("Length before the character \"%c\" is found is: %zu.\n",
//		string_3[strcspn(string_3,string_4)],strcspn(string_3,string_4));
//	}

	/* Strerror() */

//	prompt_pause();
//	prompt_header(STRERROR);
//
//	printf("Examples of what strerror() returns with custom errnum.\n");
//	printf("Locale will be ignored since it's beyond the scope of this project.\n");
//	printf("Any indice beyond 0 - %d range will be interpreted as \"unknown\":\n",error_limit);
//
//	for (int i = -2; i <= (error_limit + 2); i++)
//	{
//		printf("\t%4d -> %s\n",i,strerror(i));
//	}

	/* Strncat() */

//	prompt_pause();
//	prompt_header(STRNCAT);
//
//	// Keep string_1 intact after demonstration
//	strcpy(string_3,string_1);
//
//	printf("First string is: \"%s\"\n",string_3);
//	printf("Second string is: \"%s\"\n",string_2);
//	prompt_user("Enter a number of characters from the second string");
//
//	long unsigned int input_number;
//	if (scanf(" %lu",&input_number) != 1
//	||  input_number > strlen(string_2))
//	{
//		prompt_error("Wrong input");
//		clear_buffer();
//		return 1;
//	}
//	clear_buffer();
//
//	if (can_concatenate(string_3,string_2))
//	{
//		printf("Result in the first string: \"%s\"\n",
//		strncat(string_3,string_2,input_number));
//	}
//	else
//	{
//		prompt_error("Buffer too low");
//		return 1;
//	}

	/* Strncmp() */

//	prompt_pause();
//	prompt_header(STRNCMP);
//
//	prompt_user("Enter a number of characters to compare");
//
//	if (scanf(" %lu",&input_number) != 1)
//	{
//		prompt_error("Wronng input");
//		clear_buffer();
//		return 1;
//	}
//	clear_buffer();
//
//	printf("Sequences to compare:\n");
//	print_substring("First",string_1,input_number);
//	print_substring("Second",string_2,input_number);
//
//	if (strncmp(string_1,string_2,input_number) > 0)
//	{
//		printf("String \"%s\" is higher than string \"%s\"\n",
//		string_1,string_2);
//	}
//	else if (strncmp(string_1,string_2,input_number) < 0)
//	{
//		printf("String \"%s\" is higher than string \"%s\"\n",
//		string_2,string_1);
//	}
//	else
//	{
//		printf("Strings \"%s\" and \"%s\" are equal in the first %d bytes.\n",
//		string_1,string_2,(int)input_number);
//	}

	/* Strpbrk() */

//	prompt_pause();
//	prompt_header(STRPBRK);
//
//	// Prepare a concatenated string for demonstration
//	strcpy(string_3,string_1);
//	strcat(string_3,string_2);
//
//	printf("Your concatenated string is \"%s\"\n",string_3);
//	prompt_user("Enter a sequence of characters to be found in the string");
//
//	if (fgets(string_4,sizeof(string_4),stdin) == NULL)
//	{
//		prompt_error("Wrong input");
//		return 1;
//	}
//
//	if (string_4[strlen(string_4) - 1] == '\n')
//	{
//		clear_string(string_4);
//	}
//	else
//	{
//		clear_buffer();
//	}
//
//	if (strpbrk(string_3,string_4) == NULL)
//	{
//		printf("None of the characters were found in the string.\n");
//	}
//	else
//	{
//		prompt_char_found(string_3,strpbrk(string_3,string_4)[0],"concatenated");
//	}

	/* End of program */

	switch_display_back();
	prompt_goodbye();
	return 0;
}
