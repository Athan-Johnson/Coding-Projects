#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300; floating point version.
 * this now also uses a function. */

// convert the fahrenheit temperature given to celsius
float fahr_to_cels(float fahr);

int main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;		// lower limit of temperature table
	upper = 300;	// upper limit
	step = 20;		// step size

	// Exercise 1-3: Print a heading
	printf("---Welcome!---\n");
	printf("This table converts\nbetween Fahrenheit\n  and Celsius\n");
	printf("--------------\n");
	printf(" F:    C:\n");
	fahr = lower;
	while (fahr <= upper)
	{
		celsius = fahr_to_cels(fahr);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}

float fahr_to_cels(float fahr)
{
	float cels;

	cels = (5.0/9.0) * (fahr-32);
	return cels;
}