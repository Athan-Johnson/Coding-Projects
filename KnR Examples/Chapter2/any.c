/* This program takes in two strings, and returns the index of the first time any character from s2
 * appears in s1. In the case of no overlap it returns -1
 * Author: Athan Johnson
 * Created: 1/20/2025
 * Modified:
 */

#include <stdio.h>
#include <string.h>

#define MAXLENGTH 1000
#define STRING1 "the quick brown fox jumped over the lazy dog"
#define STRING2 "abcd"


// this function will return the first time any character in s2 appears in s1
int any(char s1[], char s2[]);

int main()
{
	int ans = any(STRING1, STRING2);

	printf("The first time these strings overlap a letter is at index: %d\n", ans);
}

int any(char s1[], char s2[])
{
	// in the outer loop we are iterating through s1
	for (int s1_index = 0; s1_index < strlen(s1); s1_index++)
	{
		// for each letter in s1 we compare it to all the letters in s2
		for (int i = 0; i < strlen(s2); i++)
		{
			if (s1[s1_index] == s2[i])
			{
				// we can just return immediately once we find the first match
				return s1_index;
			}
		}
	}
	return -1;
}
