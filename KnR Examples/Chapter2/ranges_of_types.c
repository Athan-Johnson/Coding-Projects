/* Write a program to determine the ranves of char, short, int, and long variables, both signed and unsigned, by printing
 * appropriate values from standard headers and by direct computeation. Harder if you compute them: determine the ranges 
 * of the various floating-point types.
 *
 * Author: Athan Johnson
 * Created: 1/17/2025
 * Modified:
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

	unsigned long iter = 0;

	// here we cycle through each time until the current type loops back around
	// in the case of signed we have iter be one behind and just print out the last positive value,
	// being the greatest
	// in the case of unsigned we know the min is always zero so again iter is one behind and will
	// represent the max
	while (s_char > 0)
	{
		s_char++;
		iter++;
	}


	printf("Signed Char:\t\tMin:%d\t\tMax:%ld\n", s_char, iter);

	iter = 0; // reset iter every time

	while (u_char > 0)
	{
		u_char++;
		iter++;
	}

	printf("Unsigned Char:\t\tMin:%d\t\t\tMax:%ld\n", 0, iter);

	iter = 0;

	while (s_short > 0)
	{
		s_short++;
		iter++;
	}

	printf("Signed Short:\t\tMin:%d\t\tMax:%ld\n", s_char, iter);

	iter = 0;

	while (u_short > 0)
	{
		u_short++;
		iter++;
	}

	printf("Unsigned Short:\t\tMin:%d\t\t\tMax:%ld\n", 0, iter);

	iter = 0;

	while (s_int > 0)
	{
		s_int++;
		iter++;
	}

	printf("Signed Int:\t\tMin:%d\t\tMax:%ld\n", s_int, iter);

	iter = 0;

	while (u_int > 0)
	{
		u_int++;
		iter++;
	}

	printf("Unsigned Int:\t\tMin:%d\t\t\tMax:%ld\n", 0, iter);

	iter = 0;

	while (s_long > 0)
	{
		s_long++;
		iter++;
	}

	printf("Signed Long:\t\tMin:%ld\t\tMax:%ld\n", s_long, iter);

	iter = 0;

	while (u_long > 0)
	{
		u_long++;
		iter++;
	}

	printf("Unsigned Long:\t\tMin:%d\t\t\tMax:%ld\n", 0, iter);

	iter = 0;



}
