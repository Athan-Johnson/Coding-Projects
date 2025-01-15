/* This is a program that replaces the tabs in the input with the proper number of blanks
 * Author: Athan Johnson
 * Date: 05/26/2022
 */

#include <stdio.h>

#define TAB_WIDTH 4 // change this value to change how many collumns a tab is expected to be

int main()
{
	int c, i;
	int numSpaces; // how far into the tab's space we have moved, in case we type a letter then tab

	numSpaces = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '\t') // we have a tab
		{
			for (i = 0; i < (TAB_WIDTH - numSpaces); ++i)
			{
				putchar(' ');
			}
			numSpaces = 0; // hitting a tab will always realign us
		}
		else
		{
			putchar(c);
			++numSpaces;
			if (c == '\n')
			{
				numSpaces = 0;
			}
			if ((numSpaces / TAB_WIDTH) >= 1) // we have reached the length of a tab and need to realign
			{
				numSpaces = 0;
			}
		}
	}
	putchar('\n');
}
