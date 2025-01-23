/* This program implements the invert function, this function takes in x, p, and n and outputs 
 * x with the n bits starting at position p inverted, leaving the others unchanged
 * Author: Athan Johnson
 * Created: 1/22/2025
 * Modified:
 */

#include <stdio.h>

#define X 0b10101
#define P 2
#define N 3

int invert(unsigned x, int p, int n);
void printBinary(unsigned x); 

int main()
{
	unsigned temp = invert(X, P, N);
	printf("Binary: ");
	printBinary(temp);
	printf("Actual number: %u\n", temp);
	return 0;
}


int invert(unsigned x, int p, int n)
{
	// declare variables
	unsigned part_of_x = ~0; // this is the part of x that we are going to be inverting
	unsigned mask = ~(~0 << n); // this is for deleting the bits in x that are going to
				    // be replaced with the inverted ones
	
	part_of_x = part_of_x ^ (x >> (p+1-n)); // here we are shifting the part of x we are 
						// focusing on to then end, then xor-ing it with
						// all ones so it's inverted
	part_of_x = part_of_x & ~(~0 << n); // we still have what was to the left of the section
					   // we want in x left, so we "and" part_of_x with n ones
					   // set to the right, deleting the rest

	mask = mask << (p+1-n);
	mask = ~mask;

	x = x & mask;
	x = x | part_of_x;

	return x;
	
}

void printBinary(unsigned x) {
    // Print the binary representation from most significant to least significant
    int numBits = sizeof(x) * 8;  // Get bit width
    int started = 0;  // Flag to ignore leading zeros

    for (int i = numBits - 1; i >= 0; i--) {
        if ((x >> i) & 1) {
            started = 1;  // Start printing once first 1 is encountered
            printf("1");
        } else if (started) {
            printf("0");
        }
    }

    if (!started) printf("0");  // Print at least a zero if all bits are 0

    printf("\n");
}
