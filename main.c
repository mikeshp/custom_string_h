/*
	Main program logic shared among both standard and custom main files.
	Everything must lead to equivalent results both using
	standard and custom string.h headers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "globals.h"
#include "functions.h"
#include "demo_functions.h"

#ifndef CUSTOM_LIB
	#include <string.h>
#else
	#include "my_string.h"
	#include "my_string_names.h"
#endif

int main(void)
{
	// handle cntrl-c interrupt
	signal(SIGINT,sigint_exit);
	signal(SIGHUP,sigint_exit);

	char  user_select[INPUT_SIZE];
	const int punks_not_dead = 1;

	prompt_hello();
	switch_display_alternative();

	/* Main Menu */

	while (punks_not_dead)
	{
		clear_screen();
		prompt_header(HEADER);
		// the enum shifted due to top HEADER
		// hence NUMBER - 1 to count functions
		display_menu_options(DEMO_COUNT-1);

		move_cursor_bottom();
		prompt_user("Enter your selection");
		user_input(user_select,INPUT_SIZE);

		if (user_select[0] == 'Q' || user_select[0] == 'q')
		{
			break;
		}

		switch(atoi(user_select))
		{
			case 1 ... DEMO_COUNT-1:
				demo_function(atoi(user_select));
				break;
			default:
				break;
		}
	}






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
