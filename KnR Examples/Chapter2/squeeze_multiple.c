/* this program is a more advanced version of the squeeze function, it takes in two
 * strings and deletes each character in the first string that matches any character in the second string
 * Author: Athan Johnson
 * Created: 1/20/2025
 * Modified:
 */

#include <stdio.h>
#include <string.h>

#define MAXLENGTH 1000
#define STRING1 "the quick brown fox jumped over the lazy dog"
#define STRING2 "abcde"

// this function takes in two strings, any letter in the second is deleted
// from the first
void squeezeMultiple(char s1[], char s2[]);

int main()
{
	// declare variables 
	char ans[MAXLENGTH] = STRING1;

	// we aren't overwriting string 2 so we don't need to make a variable with it
	squeezeMultiple(ans, STRING2);

	printf("%s\n", ans);
}

void squeezeMultiple(char s1[], char s2[])
{
	// now instead of c we are just keeping track of which letter in s2 we are on
	for (int s2_index = 0; s2_index < strlen(s2); s2_index++)
	{
		// use i and j to keep track of where in s1 we actually are, and where in
		// the new s1 we are writting on top of it we are. 
		// basically any time we see a letter we're good with we just copy it over,
		// but other letters are ignored. then we move on to the next letter with i
		// but j stays in its place to override what was there next time we see a
		// letter we like
		int i, j;

		for (i = j = 0; s1[i] != '\0'; i++)
		{
			if (s1[i] != s2[s2_index])
			{
				s1[j++] = s1[i];
			}
		}
		s1[j] = '\0';
	}
}
