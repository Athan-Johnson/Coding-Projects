
#include <stdio.h>

int main()
{
	int c;
	int count = 0;
	while ((c = getchar()) != EOF)
	{
		if (count == 8)
		{
			putchar(' ');
			count = 0;
		}
		putchar(c);
		count++;
	}
}
