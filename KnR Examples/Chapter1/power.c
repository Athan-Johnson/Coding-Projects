#include <stdio.h>

// a function to raise base to the power of n, edited to use the call by value aspect
int power(int m, int n);

// test the power function
int main()
{
	int i;

	for (i = 0; i < 10; ++i)
		printf("%d %3d %6d\n", i, power(2,i), power(-3,i));
	return 0;
}

// power: raise base to n-th power; n >= 0
int power(int base, int n)
{
	int p;

	p = 1;
	for (p = 1; n > 0; --n)
		p = p * base;
	return p;
}