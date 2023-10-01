#include <stdio.h>

/* count characters in input; 2st version (including ctrl-D) */
int main()
{
	double nc;

	for (nc = 0; getchar() != EOF; nc++)
		;
	printf("%.0f\n", nc); // small bug here, if there are less
						 // than 10 characters it prints the number
						 // followed by D
}
