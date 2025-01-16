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
	int prev_was_backslash = FALSE;
	int ignore_line = FALSE;
	int ignore_until_end = FALSE;
	int prev_was_star = FALSE;

	// main loop
	while ((c = getchar()) != EOF) 
	{
		// if we are not on either comment then we process as usual
		if (ignore_line == FALSE && ignore_until_end == FALSE)
		{
			// here we check if this could be the start of a comment, or the completion of a "//"
			if (c == '/')
			{
				if (prev_was_backslash == TRUE)
				{
					ignore_line = TRUE;
					prev_was_backslash = FALSE;
				}
				// in this case we are just setting up for the future possibility of a comment
				else
				{
					prev_was_backslash = TRUE;
				}
			}
			// in this case we have confirmed a "/*" comment
			else if (c == '*' && prev_was_backslash == TRUE)
			{
				ignore_until_end = TRUE;
				prev_was_backslash = FALSE;
			}
			else // print the letter as usual, we are not in a comment
			{
				// in the event the previous wasn't a backslash we didn't print it out of safety, so check if it should be printed now
				if (prev_was_backslash == TRUE)
				{
					putchar('/');
					prev_was_backslash = FALSE;
				}
				putchar(c);
			}
		}
		// in this case we are in a "/*" type of comment and need to wait for a "*/"
		else if (ignore_until_end == TRUE)
		{
			if (c == '*')
			{
				prev_was_star == TRUE;
			}
			else if (c == '/' && prev_was_star == TRUE)
			{
				ignore_until_end = prev_was_star = FALSE;
			}
		}
		else // in this case we have seen a "//" and are ignoring the line until '\n'
		{
			if (c == '\n')
			{
				ignore_line = FALSE;
				putchar('\n'); // in case a comment was put on a line with code too, just like this one
			}
		}
	}
}
