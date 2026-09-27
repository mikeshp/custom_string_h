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

#endif
