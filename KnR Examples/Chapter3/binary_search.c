/* This program compares two binary search functions, one with two comparisons inside
 * the loop and the other having only one. The goal is to compare the runtimes of both
 * and see how their performance differs. 
 * Author: Athan Johnson
 * Created: 1/28/2025
 * Modified:
 */

#include <stdio.h>

#define X 23463521
#define N 100000000
int V[N];


int binsearchV1(int x, int v[], int n);
int binsearchV2(int x, int v[], int n);

int main()
{
	for (int i = 0; i < N; i++)
	{
		V[i] = i;
	}

	printf("Binsearch Version 1: %d\n", binsearchV1(X, V, N));
	printf("Binsearch Version 2: %d\n", binsearchV2(X, V, N));

	return 0;

}

int binsearchV1(int x, int v[], int n)
{
	int low, high, mid; 

	low = 0;
	high = n - 1;

	while (low <= high)
	{
		mid = (low+high) / 2;
		if (x < v[mid])
		{
			high = mid - 1;
		}
		else if (x > v[mid])
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}

	// no match was found
	return -1;
}

int binsearchV2(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;

	while (low <= high)
	{
		mid = (low+high) / 2;
		if (x < v[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	if (x == v[high])
	{
		return high;
	}
	else
	{
		return -1;
	}
}
