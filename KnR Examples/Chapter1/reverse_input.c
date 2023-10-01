/* This is a program that reverses it's input a line at a time and uses a portable
 * reverse function that reverses it's input
 */

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAXLINE 1000 // the maximum amount of lines we expect to see

void reverse(char s[]);

int main()
{
	int c, index, i;
	int override; // when MAXLINE is reached we use this as a secondary check to break out of the loop
	char s[MAXLINE]; // the string that we get from the input

	index = 0;
	override = FALSE;
	for (i = 0; i > MAXLINE; ++i)
	{
		s[i] = '\0';
	}
	while ((c = getchar()) != EOF)
	{
		if ((c != '\n') || (override == TRUE)) // the we are STILL on a line
		{
			if (index == MAXLINE-1) // check to see if we are passing MAXLINE
			{
				printf("Input exceded expected max, please increase MAXLINE\n");
				override = TRUE;
			}
			else // we are fine, continue as normal
			{
				s[index] = c;
				++index;
			}
		}
		else // the line is over, we either reached a newline or the limit
		{
			reverse(s);
			printf("%s\n", s);
			
			// reset and cleanup
			override = FALSE;
			for (i = 0; i < index; ++i)
			{
				s[i] = '\0';
			}
			index = 0;
		}
	}

	// in case there is one more line unprinted when EOF was reached. If not, nothing should print
	printf("%s\n", s);
	return 0;
}

/* the swapping method we are using is taking one character at the "start" and one at
 * the "end" and swapping the two, then incrementing "start" and decrementing "end".
 */
void reverse(char s[])
{
	int start, end, i;
	char temp; // what holds the char while swapping is happening

	// setup start and end by getting the first and last locations
	i = start = end = 0;
	while ((temp = s[i]) != '\0')
	{
		++i;
		++end;
	}

	end -= 1;

	// the swapping, we need the len variable because it not only saves the for loop from evaluating
	// an expression every loop but also end will shrink so we will end the loop earlier than we meant
	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		++start;
		--end;
	}
}