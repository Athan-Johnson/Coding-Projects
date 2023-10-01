#include <stdio.h>

#define LOWER	0	// lower limit of the table
#define UPPER	300	// upper limit
#define STEP	20	// step size

/* print Fahrenheit-Celsius table */

int main()
{
	int fahr;

	// Exercise 1-5: Make the program print the table in
	// reverse order, from 300 to 0
	for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
