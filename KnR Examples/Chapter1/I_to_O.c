#include <stdio.h>

/* copy input to output; 2st version */
int main()
{
	int c;

	// Exercise 1-6: verify that getchar() != EOF is 0 or 1
	while (c != EOF)
	{
		// putchar(c);
		printf("%d", (getchar() != EOF));
	}
}
