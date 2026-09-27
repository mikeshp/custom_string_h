/*
	Other supplemental functions
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "globals.h"

void clear_string(char*);
void clear_buffer();
int  can_concatenate(char*,char*);
void prompt_user(const char*);
void prompt_error(const char*);
void prompt_header(enum Header);
void prompt_strings_in_order(const char*,const char*);
void prompt_char_found(const char*,const char,const char*);

#endif
