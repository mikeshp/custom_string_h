#include <stdio.h>

#include "globals.h"
#include "demo_functions.h"
#include "functions.h"

#ifndef CUSTOM_LIB
	#include <string.h>
#else
	#include "my_string.h"
	#include "my_string_names.h"
#endif

void (*demo_select[DEMO_COUNT])(void) =
{
	 demos
	,demo_strlen
	,demo_strcat
	,demo_strchr
	,demo_strcmp
	,demo_strcoll
	,demo_strcpy
	,demo_strcspn
	,demo_strerror
	,demo_strncat
	,demo_strncmp
	,demo_strpbrk
};

void demo_function(int user_select)
{
	demo_select[user_select]();
}

void demos()
{
	// index 0 placeholder
}

void demo_strlen()
{
	/* Strlen() */
	clear_screen();
	prompt_header(STRLEN);

	move_cursor_bottom();
	prompt_user("Enter a string");
	user_input(string_1,STRING_SIZE);
	printf("\n");

	redraw_header(STRLEN);

	prompt_user("Enter a second string");
	user_input(string_2,STRING_SIZE);
	printf("\n");

	redraw_header(STRLEN);

	printf("First string is %zu characters long.\n",strlen(string_1));
	printf("Second string is %zu characters long.\n",strlen(string_2));

	if (strlen(string_1) > strlen(string_2))
	{
		printf("First string is %d characters longer.\n",
		(int) (strlen(string_1) - strlen(string_2)));
	}
	else if (strlen(string_2) > strlen(string_1))
	{
		printf("Second string is %d characters longer.\n",
		(int) (strlen(string_2) - strlen(string_1)));
	}
	else
	{
		printf("Their length is equal.\n");
	}

	redraw_header(STRLEN);
	prompt_pause();
}

void demo_strcat()
{
	/* Strcat() */
	clear_screen();
	prompt_header(STRCAT);

	move_cursor_bottom();
	prompt_user("Enter a string");
	user_input(string_1,STRING_SIZE);
	printf("\n");

	redraw_header(STRCAT);

	prompt_user("Enter a second string");
	user_input(string_2,STRING_SIZE);

	redraw_header(STRCAT);

	if (can_concatenate(string_1,string_2))
	{
		printf("Two strings together: \"%s\"\n",
		strcat(string_1,string_2));

		printf("Concatenated string's length is %zu.\n",
		strlen(string_1));
	}
	else
	{
		prompt_error("Buffer too low");
	}

	redraw_header(STRCAT);
	prompt_pause();
}

void demo_strchr()
{
	/* Strchr() */
	clear_screen();
	prompt_header(STRCHR);

	move_cursor_bottom();
	prompt_user("Enter a string");
	user_input(string_1,STRING_SIZE);
	printf("\n");

	redraw_header(STRCHR);

	prompt_user("Enter a second string");
	user_input(string_2,STRING_SIZE);
	printf("\n");

	redraw_header(STRCHR);

	prompt_user("Enter a character");

	char input_char;

	if (scanf("%c",&input_char) != 1)
	{
		prompt_error("Wrong input");
	}
	else
	{
		clear_buffer();
	}

	redraw_header(STRCHR);

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

	redraw_header(STRCHR);
	prompt_pause();
}

void demo_strcmp()
{
	/* Strcmp() */
	clear_screen();
	prompt_header(STRCMP);

	move_cursor_bottom();
	prompt_user("Enter a string");
	user_input(string_1,STRING_SIZE);
	printf("\n");

	redraw_header(STRCMP);

	prompt_user("Enter a second string");
	user_input(string_2,STRING_SIZE);
	printf("\n");

	redraw_header(STRCMP);

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

	redraw_header(STRCMP);
	prompt_pause();
}

void demo_strcoll()
{
	/* Strcoll() */
	clear_screen();
	prompt_header(STRCOLL);

	// Add later
	move_cursor_bottom();
	printf("Come tomorrow.\n");

	redraw_header(STRCOLL);
	prompt_pause();
}

void demo_strcpy()
{
	/* Strcpy() */
	clear_screen();
	prompt_header(STRCPY);

	move_cursor_bottom();
	prompt_user("Enter a string");
	user_input(string_1,STRING_SIZE);
	printf("\n");

	redraw_header(STRCPY);

	printf("Attempt to make a copy of the first string in the second...");

	if (can_copy(string_2,string_1))
	{
		printf("Success!\n");
		printf("Second string (copied from the first): \"%s\"\n",
		strcpy(string_2,string_1));
	}
	else
	{
		prompt_error("Buffer too low");
	}

	redraw_header(STRCPY);
	prompt_pause();
}

void demo_strcspn()
{
	/* Strcspn() */
	clear_screen();
	prompt_header(STRCSPN);

	move_cursor_bottom();
	prompt_user("Enter a string");
	user_input(string_3,STRING_SIZE);
	printf("\n");

	redraw_header(STRCSPN);

	move_cursor_bottom();
	prompt_user("Enter a sequence of characters to find in the string");
	user_input(string_4,STRING_SIZE);
	printf("\n");

	redraw_header(STRCSPN);

	if (strcspn(string_3,string_4) == strlen(string_3))
	{
		printf("None of the characters were found in the string!\n");
	}
	else
	{
		printf("Length before the character \"%c\" is found is: %zu.\n",
		string_3[strcspn(string_3,string_4)],strcspn(string_3,string_4));
	}

	redraw_header(STRCSPN);
	prompt_pause();
}

void demo_strerror()
{
	prompt_header(STRERROR);
}

void demo_strncat()
{
	prompt_header(STRNCAT);
}

void demo_strncmp()
{
	prompt_header(STRNCMP);
}

void demo_strpbrk()
{
	prompt_header(STRPBRK);
}
