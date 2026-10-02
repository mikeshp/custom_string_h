/*
	Other supplemental functions
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "globals.h"

void print_substring(const char*,const char*,size_t);
void prompt_pause();
void prompt_goodbye();
void prompt_hello();
void display_menu_options(const int);
void clear_string(char*);
void clear_screen();
void switch_display_back();
void switch_display_alternative();
void user_input(char*);
void clear_buffer();
int  can_concatenate(const char*,const char*);
int  can_copy(const char*,const char*);
void prompt_user(const char*);
void prompt_error(const char*);
void prompt_header(enum Header);
void prompt_strings_in_order(const char*,const char*);
void prompt_char_found(const char*,const char,const char*);

#endif
