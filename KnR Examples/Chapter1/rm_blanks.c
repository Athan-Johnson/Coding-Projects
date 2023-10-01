#include <stdio.h>

/* copy input to output; then removing all strings of
 * one or more blanks with a single blank
 */

#define TURE 1
#define FALSE 0

int main()
{
	int c, lastBlank;

	lastBlank = FALSE;
	while ((c = getchar()) != EOF)
	{
		// This is first so that the first blank always gets printed
		if (c == ' ')
		{
			if (lastBlank == FALSE)
			{
				lastBlank = TURE;
				putchar(c);
			}
		}
		// is it faster to check this first each time and then update? Or to
		// just update everytime even when it's not needed
		else
		{
			lastBlank = FALSE;
			putchar(c);
		}
	}
}
