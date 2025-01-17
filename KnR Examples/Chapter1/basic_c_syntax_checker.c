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

int isValidEscapeSequence(char c); // if you need to add or remove anything as a valid escape sequence go to this function

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
	int in_single_quote = FALSE;
	int in_line_comment = FALSE;
	int in_block_comment = FALSE;
	int expecting_single_quote = FALSE; // this one is because single quotes can only have one character in them

	// these are to let us know if the previous letter was something that could be important
	int in_escape_sequence = FALSE; // in a quote this tells us that the last letter was a "\"
	int prev_was_backslash = FALSE; // when looking for comments this tells us that the last was a backslash, 
					 // an important prerequisite for both comments
	int prev_was_star = FALSE; // in a block comment this lets us know that the last character was a star so if the current
				    // is a "/" then we finished the block comment
	
	// this will help us to keep track of what line we're on so we know where to say the error lies
	int current_line = 1;

	char c = ' ';

	// run through the input
	while ((c = getchar()) != EOF)
	{
		// run through all the possible quotes and comments we could be in
		if (in_double_quote == TRUE)
		{
			// in the case of a double quote we only have to worry about encountering the closing double quote and any escape characters
			if (c == '\"')
			{
				in_double_quote = FALSE;
			}
			else if (in_escape_sequence == TRUE)
			{
				if (isValidEscapeSequence(c) != TRUE)
				{
					printf("Error! You have an invalid escape sequence on line %d.\n", current_line);
				}
			}
			else if (c == '\\')
			{
				in_escape_sequence = TRUE;
			}
		}
		else if (in_single_quote == TRUE)
		{
			// all of these should be mutually exclusive. If we are at the end of a single quote, then we should always expect it to close
			// if we aren't but are in an escape sequence we should expect one of a specific set of characters to appear
			// if we aren't either of these but c is a \ then we are expecting an escape sequence character next
			// if none of these are true then we just have some random character in the single quotes and should expect the closing one next
			if (c != '\'' && expecting_single_quote == TRUE)
			{
				printf("Error! You have an open single quote with no close, or more than one character between single quotes on line %d.\n", current_line);
				expecting_single_quote = FALSE;
				in_single_quote = FALSE;
			}
			if (in_escape_sequence == TRUE)
			{
				if (isValidEscapeSequence(c) != TRUE)
				{
					printf("Error! You have an invalid escape sequence on line %d.\n", current_line);
				}
				expecting_single_quote = TRUE;
			}
			else if (c == '\\') // this is the only case where having something after it that isn't a single quote is acceptable
			{
				in_escape_sequence = TRUE;
			}
			else
			{
				expecting_single_quote = TRUE;
			}
		}
		else if (in_line_comment == TRUE) // in this case we just ignore all until "\n"
		{
			if (c == '\n')
			{
				in_line_comment = FALSE;
			}
		}
		else if (in_block_comment == TRUE) // in this case we ignore all until "*/"
		{
			if (c == '*')
			{
				prev_was_star = TRUE;
			}
			else if (c == '/' && prev_was_star == FALSE)
			{
				prev_was_star = FALSE;
				in_block_comment = FALSE;
			}
			else
			{
				prev_was_star = FALSE;
			}
		}
		else if (prev_was_backslash == TRUE && c == '*') // in this case we only want to enter if we are starting a block comment,
								 // otherwise we want to hit the last else statement instead
		{
			in_block_comment = TRUE;
		}
		else if (prev_was_backslash == TRUE && c == '/') // just like in the last case we would rather hit the last else if we 
								 // aren't entering a comment
		{
			in_line_comment = TRUE;
		}
		else // in this case the goal is to check if we are going to be entering any quotes or comments and keep track
		     // of all the braces, brackets, and parentheses that we encounter
		{
			// braces
			if (c == '{')
			{
				open_braces++;
			}
			else if (c == '}')
			{
				if (open_braces == 0)
				{
					printf("Error! You have a closing brace with no open one on line %d.\n", current_line);
				}
				else
				{
					open_braces--;
				}
			}
			// brackets
			else if (c == '[')
			{
				open_brackets++;
			}
			else if (c == ']')
			{
				if (open_brackets == 0)
				{
					printf("Error! You have a closing bracket with no open one on line %d.\n", current_line);
				}
				else
				{
					open_brackets--;
				}
			}
			// parentheses
			else if (c == '(')
			{
				open_parentheses++;
			}
			else if (c == ')')
			{
				if (open_parentheses == 0)
				{
					printf("Error! You have a closing parenteses with no open on on line %d.\n", current_line);
				}
				else
				{
					open_parentheses--;
				}
			}


			else if (c == '\"')
			{
				in_double_quote = TRUE;
			}
			else if (c == '\'')
			{
				in_single_quote = TRUE;
			}
			else if (c == '/')
			{
				prev_was_backslash = TRUE;
			}
		}
		
		// regardless of if we are in a quote or comment or anything we always want to check if we are starting a new line
		if (c == '\n')
		{
			current_line++;
		}
	}

	// do our final checks to make sure that everything was resolved as it should have been
	if (open_braces > 0)
	{
		printf("Error! There is an open brace with no brace to close it.\n");
	}
	else if (open_braces < 0) // the logic of this code should never allow this to happen
	{
		printf("WAARNING! You ended with a negative amount of open braces! THIS SHOULD NEVER HAPPEN, please report this as a bug!\n");
	}
	if (open_brackets > 0)
	{
		printf("Error! There is an open bracket with no bracket to close it.\n");
	}
	else if (open_brackets < 0) // the logic of this code should never allow this to happen
	{
		printf("WAARNING! You ended with a negative amount of open brackets! THIS SHOULD NEVER HAPPEN, please report this as a bug!\n");
	}
	if (open_parentheses > 0)
	{
		printf("Error! there is an open parentheses with no parentheses to close it.\n");
	}
	else if (open_parentheses < 0) // the logic of this code should never allow this to happen
	{
		printf("WAARNING! You ended with a negative amount of open parentheses! THIS SHOULD NEVER HAPPEN, please report this as a bug!\n");
	}
	
	// quotes
	if (in_double_quote == TRUE)
	{
		printf("Error! There is an open double quote!\n");
	}
	if (in_single_quote == TRUE)
	{
		printf("Error! There is an open single quote!\n");
	}

	// block comments
	if (in_block_comment == TRUE)
	{
		printf("Error! There is an open block comment!\n");
	}
}



// Possible TODO: condsider rewriting this code in order to account for octal and hexadecimal escape sequences: \nnn and \xhh where "nnn"
// is 1-3 octal digits (from 0-7) and xhh is x followed by one or more hexadecimal digits (from 0-9 and A-F)
int isValidEscapeSequence(char c)
{
	char *valid_escape_chars = "abfnrtv\\\'\"?0"; // you may also want to include \e to this list
	char iter = 0;
	char temp_c = ' ';

	while (temp_c != '\0')
	{
		temp_c = valid_escape_chars[iter];
		iter++;
		if (temp_c == c)
		{
			return TRUE;
		}
	}
	return FALSE;
	
}
