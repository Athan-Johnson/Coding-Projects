/* This is a program that finds the longest line in it's input, and prints it
 * Author: Athan Johnson
 * Date: 5/26/2022
 */

#include <stdio.h>

#define MAXLINE 1000 // max input size

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getLine(void);
void copy(void);

// prints longest input line
int main()
{
	int len; // current line length
	extern int max; // max length seen so far
	extern char longest[MAXLINE];	// longest line saved here

	max = 0;
	while ((len = getLine()) > 0)
	{
		if (len > max)
		{
			max = len;
			copy();
		}
		if (len == MAXLINE-1)
			printf("\nERROR: Line exceeded maximum input, please change MAXLINE and try again\n\n");
	}
	if (max > 0) // there was a line
		printf("%s", longest);
	return 0;
}

/* getline: read a line into s, return length */
int getLine(void)
{
	int c, i;
	extern char line[];

	for (i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n')
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(void)
{
	int i;
	extern char line[], longest[];

	i = 0;
	while ((longest[i] = line[i]) != '\0')
		++i;
}