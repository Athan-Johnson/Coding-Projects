/* The goal of this assignment is to write a loop that is equivalent to the for loop
 * below without using && or ||:
 * 	for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 * 		s[i] = c;
 * Author: Athan Johnson
 * Created: 1/19/2025
 * Modified:
 */

#include <stdio.h>
#define MAXLINE 1000

int getLine(char s[], int lim);
void copy(char to[], char from[]);

// the program that we are copying is a simple getline function
int main()
{
	int len; // current line length
	int max; // max length seen so far
	char line[MAXLINE];		// current input line
	char longest[MAXLINE];	// longest line saved here

	max = 0;
	while ((len = getLine(line, MAXLINE)) > 0)
	{
		if (len > max)
		{
			max = len;
			copy(longest, line);
		}
		if (len == MAXLINE-1) // in this case now we try to copy just the first part of the line
		{
			max = MAXLINE-1;
			char shortened[MAXLINE+1]; // this will hold the first part of the line, up to MAXLINE
			for (int i = 0; i < MAXLINE; i++)
			{
				shortened[i] = line[i];
			}
			shortened[MAXLINE] = '\0';

			copy(longest, line);
		}
	}
	if (max > 0) // there was a line
	{
		printf("%s", longest);
		putchar('\n');
	}
	return 0;

}


// getline: read a line into s, return length
int getLine(char s[], int lim)
{
	int c, i;

	// here is the line we are changing, writing a loop equivalent to the original for loop
	for (i = 0; (i < lim-1) == ((c = getchar()) != EOF) == (c != '\n'); ++i)
	{
		s[i] = c;
	}

	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
