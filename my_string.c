/*
	My own implementation of the standard <String.h> functions.
	Names must follow my_[standard_name] pattern.
*/

#include <stdio.h>

#include "globals.h"
#include "my_string.h"
#include "my_string_names.h"

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

char* my_strncat(char* destin, const char* source, size_t number)
{
	int l = (int) strlen(destin);
	int i;

	for (i = 0; i < (int) number; i++)
	{
		destin[l + i] = source[i];
	}

	destin[l + i] = '\0';

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

int my_strncmp(const char* str1, const char* str2, size_t number)
{
	int ptr = 0;

	while (ptr < (int) number)
	{
		if (str1[ptr] != str2[ptr]
		||  str1[ptr] == '\0' || str2[ptr] == '\0')
		{
			return str1[ptr] - str2[ptr];
		}

		ptr++;
	}

	return 0;
}

char* my_strcpy(char* destin, const char* source)
{
	int ptr = 0;

	while (source[ptr] != '\0')
	{
		destin[ptr] = source[ptr];
		ptr++;
	}

	destin[ptr] = '\0';

	return destin;
}

size_t my_strcspn(const char* string, const char* chars)
{
	int ptr = 0;
	size_t occ = strlen(string);
	size_t smaller_occ = occ;

	while (chars[ptr] != '\0')
	{
		if (strchr(string,chars[ptr]) != NULL
		&& (smaller_occ = strlen(string)
		-   strlen(strchr(string,chars[ptr])))
		<   occ)
		{
			occ = smaller_occ;
		}

		ptr++;
	}

	return occ;
}

char* my_strerror(int errnum)
{
	if (errnum >= 0 && errnum < error_limit)
	{
		return error_lines[errnum];
	}

	static char unknown_error[] = "Unknown error";
	static char error_number[20];
	strcpy(error_number,unknown_error);
	strcat(error_number," ");

	// since we can't use external functions
	// have to convert errnum into a string
	static char errnum_convert[8];
	int ptr = 0;

	if (errnum < 0)
	{
		errnum_convert[ptr] = '-';
		errnum = errnum * -1;
		ptr++;
	}

	while (errnum != 0)
	{
		int cut;
		int dig;

		// get the left digit from errnum
		cut = errnum;
		while (cut != 0)
		{
			dig = cut;
			cut = cut / 10;
		}

		// write the left digit under the pointer
		errnum_convert[ptr] = (char) dig + '0';
		ptr++;

		// cut the left digit from errnum
		cut = errnum / 10;
		while (cut != 0)
		{
			dig = dig * 10;
			cut = cut / 10;
		}

		errnum = errnum - dig;
	}

	errnum_convert[ptr] = '\0';
	strcat(error_number,errnum_convert);

	return error_number;
}
