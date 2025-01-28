/* This program is a faster version of bitcount than the example shown in the book. Here we
 * take advantage of the fact that x &= x-1 deletes the rightmost bit in a two's complement
 * system
 * The reason this works is easiest to show with an example: takes nine: 1001
 * 	9-1 = 1000
 * 	1001 & 1000 = 1000, deleting the 1 on the right. now if we do this again
 * 	8-1 = 0111
 * 	1000 & 0111 = 0000, now we have deleted the 1 on the far left, which for
 * 				eight is the rightmost one bit. 
 *
 * Let's look at negative numbers
 * 	-9-1 = 1111 0110 + 1111 1110 = 1111 0100 (if you do this yourself you'll notice that
 * 							there is a one that is meant to be
 * 							carried into the ninth digit place
 * 							here but is discarded, in two's complement
 * 							as long as the rightmost bits are
 * 							unchanged at the end this is fine)
 * 	1111 0110 & 1111 0100 = 1111 0100
 *
 * Author: Athan Johnson
 * Created: 1/27/2025
 * Modified:
 */

#include <stdio.h>

#define NUMBER 123

int bitcount(unsigned x);
int oldBitcount(unsigned x);

int main()
{
	unsigned var = NUMBER;

	printf("Fast bitcount count: %d\n", bitcount(var));
	printf("Slow bitcount count: %d\n", oldBitcount(var));

	return 0;
}

int bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x &= x-1)
	{
		b++;
	}

	return b;
}

int oldBitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x >>= 1)
	{
		if (x & 01)
		{
			b++;
		}
	}
	return b;
}
