#include <stdio.h>

/* This program prints each word it recieves on a separate line, and
 * in the case of multiple whitespaces in a row is smart enough to have
 * the next word still be on the next line, not print a lot of spaces */

#define IN 0 // inside a word
#define OUT 1 // outside a word
#define FALSE 0 // if the last character printed wasn't a newline
#define TRUE 1 // if the last character printed was a newline

int main()
{
    int c, nl_last;

    nl_last = TRUE; // if the first character is blank we won't print an extra line
    while ((c = getchar()) != EOF)
    {
        // here we check if something that could break a word is present, then we
        // change the state. Else we're in a word so print the character
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (nl_last == FALSE) // this stops us from printing a ton of spaces in between words
                putchar('\n'); // there's no need for spaces or tabs so just print the line each time
            nl_last = TRUE;
        }
        else
        {
            nl_last = FALSE;
            putchar(c);
        }
    }
}