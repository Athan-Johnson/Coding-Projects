/* This is a program that removes all trailing blanks and tabs from any line of
 * input, and deletes entirely blank lines.
 */

/* Possible conditions:
 *	1. We get a normal character and there were no blanks in front; print it
 * 	2. We get a blank character; store it
 *	3. We get a normal character and there were blanks or a newline in front; check if we need to print the
 		stored blank characters and print that if we do, print the character regardless
 *	4. We get a newline; reset storage and flags, if only blanks don't print it else do
 * Condensed logic:
 *	1. If normal character: (if stored blanks: (print stored blanks) print normal character)
 *	2. If newline: (if no normal characters between this and last newline: (skip printing, unstore any 
 		stored blanks) else: (print newline))
 *	3. If blank: (store and set flags)
 */

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAXLINE 1000 // the most amount of blanks we expect to see in a row

void clearStored(char *str, int idx);

int main()
{
	int c, index, i;
	int wasChar; 		// either TRUE or FALSE, true if the line had a char false if so far only blanks
	char stored[MAXLINE] = { '\0' };	// the stored consecutive blanks

	index = 0;

	while ((c = getchar()) != EOF)
	{
		if (c != ' ' && c != '\t' && c != '\n') // c is a normal character
		{
			if (index > 0)
			{
				printf("%s",stored);
				clearStored(stored, index);
				index = 0;
			}
			putchar(c);
			wasChar = TRUE;
		}
		else if (c == '\n') // c is a newline
		{
			if (wasChar == TRUE) // there were characters on this line
			{
				putchar(c);
				wasChar = FALSE;
				clearStored(stored, index);
				index = 0;
			}
			else // the whole line was empty and should be deleted
			{
				clearStored(stored, index);
				index = 0;
			}
		}
		else // c is a blank by process of elimination
		{
			stored[index] = c;
			++index;
		}
	}
	return 0;
}

void clearStored(char *str, int idx)
{
	for (int i = 0; i < idx; ++i)
	{
		str[i] = '\0';
	}
}