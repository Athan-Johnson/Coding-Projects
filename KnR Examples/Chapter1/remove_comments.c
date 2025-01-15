/* This is a program that will remove all comments from a C program.
 * Author: Athan Johnson
 * Created: 1/15/2025
 */

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main() {
	// declare variables	
	char c = ' ';
	int prev_was_backslash = ignore_line = ignore_until_end = FALSE;

	// main loop
	while ((c = getchar()) != EOF) 
	{
		// if we are not on a "//" comment then we process as usual
		if (ignore_line == FALSE)
		{
			// here we check if we see the "//" type of comment has been seen
			if (c == '/')
			{
				if (prev_was_backslash == TRUE)
				{
					ignore_line = TRUE;
				}
				else
				{
					prev_was_backslash = TRUE;
				}
			}
			// here we check if the 
		}
		else // in this case we have seen a "//" and are ignoring the line and only stop at \n
		{
			if (c == '\n')
			{
				ignore_line = FALSE;
			}
		}
	}
}
