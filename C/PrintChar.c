
#include <stdio.h>  /* getchar, puts */
#include <string.h> /* strcmp        */

#include"ws4.h"

void IfElse(void);
void SwitchCase(void);
void LutFunc(void);

static void Exit(void);
static void PrintA(void);
static void PrintT(void);
static void PrintNoting(void);
static void (*ptr_a)(void) = &PrintA;
static void (*ptr_t)(void) = &PrintT;
static void (*ptr_noting)(void) = &PrintNoting;
static void (*ptr_exit)(void) = &Exit;

void PrintChar(int argc, char **argv)
{
	/* must have 2 arguments exactly */
	if (argc != 2)
	{
		puts("Invalid amount of arguments\n");
		return; 
	}
	if(0 == strcmp(argv[1],"1"))
	{
		IfElse();
	}
	else if(0 == strcmp(argv[1],"2"))
	{
		SwitchCase();
	}
	else if (0 == strcmp(argv[1],"3"))
	{
		LutFunc();
	} 
	else
	{
		puts("Please choose number between 1-3\n");
		puts("1.If else\t2.switch csae\t3.LUT table");
	}
}

void IfElse(void)
{
	int set_char;
	
	do
	{
		set_char = getchar();
		if (set_char == 'A')
		{
			PrintA();
		}
		else if (set_char == 'T')
		{
			PrintT();
		}
		
	} while(set_char != 27); /*ESC*/
	return;
}

void SwitchCase(void)
{
	char set_char;
	
	do
	{
		set_char = getchar();
		switch (set_char)
		{
		case 'A':
			PrintA();
			break;
		case 'T':
			PrintT();
			break;
		default:
			break;
		}
	}
	while(set_char != 27); /*ESC*/
	return;
}

void LutFunc(void) 
{
	typedef void (*luc) (void);
	luc table[256]; 
	
	int set_char, i = 0;
	
	for (i = 0; i < 256; i++)
	{
		table[i] = ptr_noting;
	}
	
	table[27] = ptr_exit;
	table[65] = ptr_a;
	table[84] = ptr_t;
	
	do
	{
		set_char = getchar();
		table[set_char]();
		
	} while(set_char != 27); /*infinity loop*/
	
	return; /* exit the function */
}

static void PrintNoting(void){}

static void Exit(void){return;}

static void PrintA(void) 
{
	puts("pressed A");
}
static void PrintT(void) 
{
	puts("pressed T");
}





