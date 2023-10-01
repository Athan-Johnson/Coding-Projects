#include <stdio.h>

/* count lines in input */
int main()
{
	int c, bl, tab, nl;

	bl = 0;
	tab = 0;
	nl = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
			++bl;
		else if (c == '\t')
			++tab;
		else if (c == '\n')
			++nl;
	}
	printf("Blanks: %3d  Tabs: %2d  Newlines: %2d", bl, tab, nl);
}
