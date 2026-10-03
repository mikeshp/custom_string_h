#ifndef DEMO_FUNCTION_H
#define DEMO_FUNCTION_H

enum Demos
{
	 DEMOS
	,DEMO_STRLEN
	,DEMO_STRCAT
	,DEMO_STRCHR
	,DEMO_STRCMP
	,DEMO_STRCOLL
	,DEMO_STRCPY
	,DEMO_STRCSPN
	,DEMO_STRERROR
	,DEMO_STRNCAT
	,DEMO_STRNCMP
	,DEMO_STRPBRK
	,DEMO_COUNT
};

void demo_function(int);

void demos(void);
void demo_strlen(void);
void demo_strcat(void);
void demo_strchr(void);
void demo_strcmp(void);
void demo_strcoll(void);
void demo_strcpy(void);
void demo_strcspn(void);
void demo_strerror(void);
void demo_strncat(void);
void demo_strncmp(void);
void demo_strpbrk(void);

#endif

