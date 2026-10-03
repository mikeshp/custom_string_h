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

	/* End of program */

	switch_display_back();
	prompt_goodbye();
	return 0;
}
