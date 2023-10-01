/* This program takes a C file and adjusts the indentation to be correct
 * Author: Athan Johnson
 * 05/27/2022
 */

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define TAB_WIDTH 8
#define MAX_LOGIC_STATEMENT_WIDTH 6 // a while loop is 5 characters, +1 for '\0'

// void cleanString(char str[], int buf); // a function that sets a string to all '\0'
// int forming_logic_statement(char next, char str[], int index); // a function that sees if 
	// the character is part of a logic statement by checking if the char it is passed
	// placed in the index of the string it is given is forming a logic statement

int main()
{
	int c, i;
	int dist; // this represents your distance from the left margin on the line we are on
	int numIndents; // this variable keeps track of how many tabs this line should be indented
	// int specialIndent; // either TURE or FALSE, this is for an if statement or while loop that
						// has no "{ }", in which case we indent exactly the next statment
	int allBlanks; // either TRUE or FALSE, true if the line has so far been all whitespace,
					// false if we've seen a character
	// char specialStorage[MAX_LOGIC_STATEMENT_WIDTH];

	/* for (i = 0; i < MAX_LOGIC_STATEMENT_WIDTH; ++i)
	{
		specialStorage[i] = '\0';
	} */

	dist = numIndents = 0;
	// specialIndent = FALSE;
	allBlanks = TRUE;
	while ((c = getchar()) != EOF)
	{
		if (c == '{') // we should indent everthing from here to the next '}'
		{
			putchar(c);
			++numIndents;
			allBlanks = FALSE;
			// cleanString(specialStorage, MAX_LOGIC_STATEMENT_WIDTH);
		}
		else if (c == '}') // the extra indenting is over
		{
			putchar(c);
			--numIndents;
			allBlanks = FALSE;
			// cleanString(specialStorage, MAX_LOGIC_STATEMENT_WIDTH);
		}
		else if (c == '\n')
		{
			putchar('\n');
			for (i = 0; i < numIndents; ++i) // it's easier to just format the line as soon as it's made
			{
				putchar('\t');
			}
			allBlanks = TRUE; // starting a newline so back to being empty
			// cleanString(specialStorage, MAX_LOGIC_STATEMENT_WIDTH);
		}
		else if (allBlanks == TRUE && (c == ' ' || c == '\t')) // we already print the blanks so we don't need these
		{
			// cleanString(specialStorage, MAX_LOGIC_STATEMENT_WIDTH);
		}
		else if (c == ' ' || c == '\t') // the line has had characters on it
		{
			putchar(c);
			// cleanString(specialStorage, MAX_LOGIC_STATEMENT_WIDTH);
		}
		 else
		 {
			 putchar(c);
			 allBlanks = FALSE;
		 }
	}
	return 0;
}

/* void cleanString(char str[], int buf)
{
	int i;

	for (i = 0; i < buf; ++i)
	{
		str[i] = '\0';
	}
} */

/* this function is meant to be portable and doesn't assume you have the TRUE and FALSE define statments
 * it also assumes the user will clean the string themselves if it returns a value of 0 (false)
 * A return value of 1 means it's forming a logic statement but not finished, two means it's a
 * completed logic statement
 */
/* int forming_logic_statement(char next, char str[], int index)
{
	int i;
	int isPartOfStr; // either TRUE or FALSE, true if we are forming a logic statement false if not
	int numLS; // the number of logic statements, here in case this needs to be adapeted for switchs

	isPartOfStr = 0;
	numLS = 3;

	char LS[3][6] = 	{ {'i', 'f', '\0', '\0', '\0', '\0'},	// a string to store the sequence for an if statement plus '\0'
					{'f', 'o', 'r', '\0', '\0', '\0'},			// ditto but for for loops
					{'w', 'h', 'i', 'l', 'e', '\0'} };			// ditto but for while loops

	if (index == 0)
	{
		for (i = 0; i < numLS; ++i)
		{
			if (LS[i][index] == next)
			{
				isPartOfStr = 1;
			}
		}
	}
	else if (index == 1)
	{
		if (LS[0][0] == str[0]) // are we forming an if?
		{
			if (LS[0][index] == next)
			{
				isPartOfStr = 2; // we formed a completed if statement
			}
		}
		else for (i = 1; i < numLS; ++i)
		{
			if (LS[i][index] == next)
			{
				isPartOfStr = 1;
			}
		}
	}
	else if (index == 2)
	{
		if (LS[1][0] == str[0]) // are we forming a for?
		{
			if (LS[1][index] == next)
			{
				isPartOfStr = 2; // we formed a completed for loop
			}
		}
		else if (LS[2][0] == str[0]) // are we forming an if?
		{
			if (LS[2][index] == next)
			{
				isPartOfStr = 1;
			}
		}
	}
} */