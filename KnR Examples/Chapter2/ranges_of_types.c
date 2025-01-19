/* Write a program to determine the ranves of char, short, int, and long variables, both signed and unsigned, by printing
 * appropriate values from standard headers and by direct computeation. Harder if you compute them: determine the ranges 
 * of the various floating-point types.
 *
 * Author: Athan Johnson
 * Created: 1/17/2025
 * Modified: 1/19/2025
 */

#include <stdio.h>


int main ()
{
	// declare variables
	signed char s_char = 1;
	unsigned char u_char = 1;
	signed short s_short = 1;
	unsigned short u_short = 1;
	signed int s_int = 1;
	unsigned int u_int = 1;
	signed long s_long = 1;
	unsigned long u_long = 1;

	unsigned long iter = 1;

	// here we cycle through each time until the current type loops back around
	// in the case of signed we have iter be one behind and just print out the last positive value,
	// being the greatest
	// in the case of unsigned we know the min is always zero so again iter is one behind and will
	// represent the max
	while (s_char > 0)
	{
		s_char = s_char*2;
		iter = iter*2;
	}


	printf("Signed Char:\t\tMin:%d\t\t\tMax:%ld\n", s_char, iter-1);

	iter = 1; // reset iter every time

	while (u_char > 0)
	{
		u_char = u_char*2;
		iter = iter*2;
	}

	printf("Unsigned Char:\t\tMin:%d\t\t\t\tMax:%ld\n", 0, iter-1);

	iter = 1;

	while (s_short > 0)
	{
		s_short = s_short*2;
		iter = iter*2;
	}

	printf("Signed Short:\t\tMin:%d\t\t\tMax:%ld\n", s_char, iter-1);

	iter = 1;

	while (u_short > 0)
	{
		u_short = u_short*2;
		iter = iter*2;
	}

	printf("Unsigned Short:\t\tMin:%d\t\t\t\tMax:%ld\n", 0, iter-1);

	iter = 1;

	while (s_int > 0)
	{
		s_int = s_int*2;
		iter = iter*2;
	}

	printf("Signed Int:\t\tMin:%d\t\t\tMax:%ld\n", s_int, iter-1);

	iter = 1;

	while (u_int > 0)
	{
		u_int = u_int*2;
		iter = iter*2;
	}

	printf("Unsigned Int:\t\tMin:%d\t\t\t\tMax:%ld\n", 0, iter-1);

	iter = 1;

	while (s_long > 0)
	{
		s_long = s_long*2;
		iter = s_long;
	}

	printf("Signed Long:\t\tMin:%ld\tMax:%ld\n", s_long, iter-1);

	iter = 1;
	u_long = 2; // this is because now we are at the limit of unsigned long and need to know ahead of time when it will go over

	while (u_long > 0)
	{
		u_long = u_long*2;
		iter = iter*2;
	}
	iter = iter + (iter - 1); // it's essential that we add the exact right number to iter before it overflows because
				  // otherwise it'll overflow back to zero

	printf("Unsigned Long:\t\tMin:%d\t\t\t\tMax:%lu\n", 0, iter);

}
