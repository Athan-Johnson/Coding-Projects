/* This is a program that "folds" lines that pass a certain max input into two separate lines.
 * If the line is long enough it will get folded multiple times, and if there are no blanks
 * or spaces to separate out words then it cuts the word right there and folds onto the
 * next line.
 * Author: Athan Johnson
 * Date 6/8/2022
 */

#include <stdio.h>

#define MAXLEN 80 // the max length of a line that we would like to have after the folding
#define TRUE 1
#define FALSE 0

int main()
{
	int c, i;
	int index; // our placement on the line so far
	int wordLen; // the length of the word we have stored so far
	int oneWord; // either TURE or FALSE, true if the line has been all one word false if not
	char word[MAXLEN];

	for (i = 0; i < MAXLEN; ++i)
	{
		word[i] = '\0';
	}
	index = wordLen = 0;

	while ((c = getchar()) != EOF)
	{
		// deciding what to do with what is in c
		if (c == ' ' || c == '\t' || c == '\n') // we have encountered a blank/tab/newline, it's safe to print word
		{
			printf("%s", word);
			for (i = 0; i < wordLen; ++i)
			{
				word[i] = '\0';
			}
			wordLen = 0;
			putchar(c);
			if (c != '\n') // it's a blank or tab
			{
				oneWord = FALSE;
			}
			else // it's a newline character
			{
				oneWord = TRUE;
				index = 0;
			}
		}
		else
		{
			word[wordLen] = c;
			++wordLen;
		}

		// keeping track of when we end a line
		++index;
		if (index == MAXLEN)
		{
			if (oneWord == TRUE)
			{
				printf("%s\n", word);
				for (i = 0; i < wordLen; ++i)
				{
					word[i] = '\0';
				}
				index = wordLen = 0;
			}
			else
			{
				printf("\n%s", word);
				for (i = 0; i < wordLen; ++i)
				{
					word[i] = '\0';
				}
				wordLen = index = 0;
			}
		}
	}
	return 0;
}
