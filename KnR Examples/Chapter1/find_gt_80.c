/* This is a program that finds all lines greater than 80 characters
 * Author: Athan Johnson
 * Date: 5/21/2020
 */

#include <stdio.h>

#define MAXLINE 1000	// max input size
#define MOSTLINES 1000	// most amount of lines you should expect
#define MINLEN 80		// the minimum amount of lines we're looking for

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

// prints longest input line
int main()
{
	int index, i;
	int len; 	// current line length
	char line[MAXLINE];					// current input line
	char longLines[MOSTLINES][MAXLINE];	// longest line saved here

	while ((len = getLine(line, MAXLINE)) > 0)
	{
		if (len > MINLEN)
		{
			copy(longLines[index], line);
			++index;
		}
		if (len == MAXLINE-1)
			printf("\nERROR: Line exceeded maximum input, please change MAXLINE and try again\n\n");
	}
	if (index > 0) // there was a line
		for (i = 0; i <= index; ++i)
		{
			printf("%s", longLines[i]);
		}
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