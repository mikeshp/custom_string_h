/*
	My own implementation of the standard <String.h> functions.
	Names must follow my_[standard_name] pattern.
*/

#include <stdio.h>

#include "my_string.h"

size_t my_strlen(const char* string)
{
	int count = 0;

	while (string[count] != '\0' && string[count] != EOF)
	{
		count++;
	}

	return (size_t) count;
}

char* my_strcat(char* destin, const char* source)
{
	int ptr_dst = 0;
	int ptr_src = 0;

	while (destin[ptr_dst] != '\0')
	{
		ptr_dst++;
	}

	while (source[ptr_src] != '\0')
	{
		destin[ptr_dst] = source[ptr_src];
		ptr_dst++;
		ptr_src++;
	}

	destin[ptr_dst] = '\0';

	return destin;
}

char* my_strchr(const char* str, const int chr)
{
	int ptr = 0;

	while (str[ptr] != '\0' && str[ptr] != EOF)
	{
		if (str[ptr] == chr)
		{
			// gcc won't let return char* because it would
			// discard 'const' qualifier, hence the cast
			return (char*)&str[ptr];
		}

		ptr++;
	}

	return NULL;
}

int my_strcmp(const char* str1, const char* str2)
{
	int ptr = 0;
	int dif = 0;

	while ((dif = str1[ptr] - str2[ptr]) == 0
	&&     (str1[ptr] && str2[ptr]))
	{
		ptr++;
	}

	return dif;
}
