/* This is a program that finds the longest line in it's input, and prints it
 * Author: Athan Johnson
 * Date: 5/20/2022
 */

#include <stdio.h>

#define MAXLINE 1000 // max input size

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

// prints longest input line
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
		if (len == MAXLINE-1)
			printf("\nERROR: Line exceeded maximum input, please change MAXLINE and try again\n\n");
	}
	if (max > 0) // there was a line
		printf("%s", longest);
	return 0;
}

/* getline: read a line into s, return length */
int getLine(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
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