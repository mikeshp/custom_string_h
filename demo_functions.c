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

void (*demo_function_select[DEMO_COUNT])(void) =
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
	clear_screen();
	demo_function_select[user_select]();
	prompt_pause();
}

void demos()
{
	// index 0 placeholder
}

void demo_strlen()
{
	/* Strlen() */
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
}

void demo_strcat()
{
	/* Strcat() */
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
}

void demo_strchr()
{
	/* Strchr() */
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
}

void demo_strcmp()
{
	/* Strcmp() */
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
}

void demo_strcoll()
{
	prompt_header(STRCOLL);
}

void demo_strcpy()
{
	prompt_header(STRCPY);
}

void demo_strcspn()
{
	prompt_header(STRCSPN);
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
