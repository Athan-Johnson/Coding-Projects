#include <stdio.h>

/* count lines in input */
int main()
{
	int c, nl;

	nl = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nl;
	printf("%d \n", nl); // the space is there so that way if there's less
						 // than 10 lines and you're doing this on the std
						 // I/O and use ctrl-D you won't have a "D" after
						 // the number of lines
}
