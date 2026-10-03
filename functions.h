/*
	Other supplemental functions
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "globals.h"

void print_substring(const char*,const char*,size_t);
void prompt_pause(void);
void prompt_goodbye(void);
void prompt_hello(void);
void display_menu_options(const int);
void clear_string(char*);
void clear_screen(void);
void switch_display_back(void);
void switch_display_alternative(void);
void user_input(char*,const int);
void move_cursor_top(void);
void move_cursor_bottom(void);
void redraw_header(const int);
void clear_buffer(void);
void sigint_exit(int);
int  can_concatenate(const char*,const char*);
int  can_copy(const char*,const char*);
void prompt_user(const char*);
void prompt_error(const char*);
void prompt_header(const int);
void prompt_strings_in_order(const char*,const char*);
void prompt_char_found(const char*,const char,const char*);

#endif
