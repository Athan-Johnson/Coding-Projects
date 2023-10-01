#include <stdio.h>

/* This is just a special function that will print to a file special characters
 * for programs that I need to test, such as \b */

int main()
{
    char string[10]; // a nine character string with /n on the end

    // this loop fills it with null terminators, so after this add whatever chars
    // you want to test
    for (int i = 0; i < 10; i++)
        string[i] = '\0';
    string[0] = 'a';
    string[1] = 'b';
    string[2] = '\b';
    string[3] = '\t';
    string[4] = '\\';

    printf("%s\n", string);
}