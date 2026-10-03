#include <stdio.h>

#include "globals.h"
#include "demo_function.h"
#include "functions.h"

#ifndef CUSTOM_LIB
	#include <string.h>
#else
	#include "my_string.h"
	#include "my_string_names.h"
#endif

enum Demos
{
	 DEMOS
	,DEMO1
	,DEMO2
	,DEMO_COUNT
};

void (*demo_function_select[DEMO_COUNT])(void) =
{
	 demos
	,demo_1
	,demo_2
};

void demo_function(int user_select)
{
	demo_function_select[user_select]();
}

void demos(void)
{
	printf("demos\n");
}
void demo_1(void)
{
	printf("demo 1\n");
}
void demo_2(void)
{
	printf("demo 2\n");
}
