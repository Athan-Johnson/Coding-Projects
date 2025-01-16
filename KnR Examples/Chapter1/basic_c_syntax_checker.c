/* This program checks a C file for basic syntax mistakes. The list of mistakes that it will check:
 * 	- unbalanced parentheses, brackets, and braces
 * 	- check for unbalanced quotes (single and double)
 * 	- escape sequences (this is all the stuff like \n, \t, etc.)
 * 	- and comments
 * Author: Athan Johnson
 * Created: 1/16/2025
 */


#include <stdio.h>

#define TRUE 1
#define FALSE 0


int main()
{
	// declare variables
	// these are going to count up by one every time an open one is seen, and down by one every time a closed one is seen
	// if we every go into the negatives or end the file with this not being zero a mistake was made
	int open_parentheses = 0;
	int open_braces = 0;
	int open_brackets = 0;

	// these are going to tell us if we're in a mode where we're just ignoring everything until told otherwise
	int in_double_quote = FALSE; // if the file ends with either of these comment ones being TRUE there's a bug
	int in single_quote = FALSE;
	int in_line_comment = FALSE;
	int in_block_comment = FALSE;

	// these are to let us know if the previous letter was something that could be important
	int in_escape_sequence = FALSE; // in a quote this tells us that the last letter was a "\"
	int prev_was_backslash == FALSE; // when looking for comments this tells us that the last was a backslash, 
					 // an important prerequisite for both comments
	int prev_was_star == FALSE; // in a block comment this lets us know that the last character was a star so if the current
				    // is a "/" then we finished the block comment

	char c = ' ';

	// run through the input
	while ((c = getchar()) != EOF)
	{
		// run through all the possible quotes and comments we could be in
		if (in_double_quote == TRUE)
		{
		}
		if (in_single_quote == TRUE)
		{
		}
		if (in_line_comment == TRUE) // in this case we just ignore all until "\n"
		{
			if (c == '\n')
			{
				in_line_comment == FALSE
			}
		}
		if (in_block_comment == TRUE) // in this case we ignore all until "*/"
		{
		}
	}
}
