#include <stdio.h>

#include "globals.h"
#include "demo_function.h"

#ifndef CUSTOM_LIB
	#include <string.h>
#else
	#include "my_string.h"
	#include "my_string_names.h"
#endif

void demo_function(int user_select)
{
	printf("You selected %d - %s\n",user_select,header_lines[user_select]);
}
