/* This program is a rewritten version of the lower program, which converts upper
 * case letters to lower case using the conditional expressions instead of if else
 * Author: Athan Johnson
 * Created: 1/28/2025
 * Modified:
 */


#include <stdio.h>

#define LETTER ';'

int lower(int c);

int main()
{
	printf("Original Letter: %c\nLower Case Letter: %c\n", LETTER, lower(LETTER));
	return 0;
}

int lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
