#include <stdio.h>

/* A program I need for debugging that explicitly says all characters that are normally
 * hidden such as tabs, newlines, and EOF */

int main()
{
	int c;

	while ((c = getchar()) != EOF)
	{
		if (c == '\t') // tabs
		{
            printf("\\t");
		}
		else if (c == '\b') // backspaces
		{
            printf("\\b");
		}
        else if (c == '\\') // backslashes
        {
            printf("\\\\");
        }
        else if (c == '\n') // newlines
        {
            printf("\\n\n");
        }
        else
            putchar(c); // everything else
	}
	printf("[EOF]"); // end of file
	putchar('\n');
}
