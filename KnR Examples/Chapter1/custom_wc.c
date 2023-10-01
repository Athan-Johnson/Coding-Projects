#include <stdio.h>

/* This program counts the number of lines, words, and characters.
 * It's a beginner's version of wc */

#define IN 0 // inside a word
#define OUT 1 // outside a word

int main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        ++nc; // characters are easy, literally every time add to this
        if (c == '\n')  // we need to check if there's a new line, which is simple
            ++nl;
        // checking for words is a little more complicated, and is done here:
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }
    printf("Lines: %d\t Words: %d\t Characters: %d", nl, nw, nc);
}