/* This is a program that replaces strings of blanks with the minimum number of 
 * tabs to acheive the same result. The spacing of tabs is assumed to be the same
 * as the "detab" program, and when a single tab or a single space is enough to 
 * reach tab stop the space is given preference. However if you would like to
 * change this behavior of the program change the PREF_BL (prefer blanks) value
 * to false, i.e. 0
 * Author: Athan Johnson
 * 05/31/2022
 */

#include <stdio.h>

#define TAB_WIDTH 4
#define TURE 1
#define FALSE 0
#define PREF_BL 1

int main()
{
	int i, c;
	int index; // this tells ranges from 0-TAB_WIDTH and is how far past a tab stop we are
	int blanks; // this is is the number of consecutive blanks seen, and resets with index

	index = blanks = 0;
	while ((c = getchar()) != EOF)
	{
		if (index == TAB_WIDTH) // we have reached a tab stop
		{
			if (blanks == 1) // we have one consecutive blank
			{
				if (PREF_BL == TURE) // we want blanks over tabs if only one tab stop
				{
					putchar(' ');
				}
				else
				{
					putchar('\t');
				}
			}
			else if (blanks > 1) // we have more than one consecutive blank
			{
				putchar('\t');
			}

			index = blanks = 0;
		} // ending dealing with tab stops

		++index; // it's important we do this BEFORE the rest of the code because if we
				// have a newline or tab then this should be reset and NOT increment

		// here we look at the character given and decide what to do with it from here
		if (c == ' ')
		{
			++blanks;
		}
		else
		{
			// whenever we see a blank we "hold" it in case it will be overwritten by a
			// tab later. In the case of a letter though that's not the case so print the
			// "held" blanks
			for (i = 0; i < blanks; ++i)
			{
				putchar(' ');
			}
			putchar(c);
			blanks = 0;
			if (c == '\n' || c == '\t')
			{
				index = 0;
			}
		}
	}

	return 0;
}