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
	demo_function_select[user_select]();
}

void demos()
{
	// index 0 placeholder
}

void demo_strlen()
{
	prompt_header(STRLEN);
}

void demo_strcat()
{
	prompt_header(STRCAT);
}

void demo_strchr()
{
	prompt_header(STRCHR);
}

void demo_strcmp()
{
	prompt_header(STRCMP);
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
