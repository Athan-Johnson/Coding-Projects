#include <stdio.h>

/* print Celsius-Fahrenheit table
 * for fahr = 0, 20, ..., 300; floating point version */

int main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;		// lower limit of temperature table
	upper = 300;	// upper limit
	step = 20;		// step size

	// Exercise 1-3: Print a heading
	printf("---Welcome!---\n");
	printf("This table converts\nbetween Celsius\nand Fahrenheit\n");
	printf("--------------\n");
	printf(" C:    F:\n");
	celsius = lower;
	while (celsius <= upper)
	{
		fahr = ((9.0/5.0) * celsius) + 32;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
