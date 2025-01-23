/* This program, setbits(x, p, n, y), returns x with the n bits that begin at position p set to the
 * rightmost n bits of y, leaving the other bits unchanged
 * Example: x = 100101 p = 4 n = 2 y = 101; ans = 101101
 * Author: Athan Johnson
 * Created: 1/21/2025
 * Modified: 1/22/2025
 */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
void printBinary(unsigned x);

#define X 0b101010
#define Y 0b101
#define P 3
#define N 3

int main ()
{
	unsigned temp = setbits(X, P, N, Y);

	printf("Binary: ");
	printBinary(temp);
	printf("Actual number: %u\n", temp);
	return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	// declare variables
	unsigned rightmost_y = 0;
	unsigned mask = ~(~0 << n); // this is for deleting the bits in x from p to p-n
	
	rightmost_y = y & ~(~0 << n); // this gets us y's rightmost n bits
	
	mask = mask << (p+1-n); // we now set up the mask to be all one's in the spot we're deleting
	mask = ~mask; // then we switch all the bits
	
	rightmost_y = rightmost_y << (p+1-n);

	x = x & mask;
	x = x | rightmost_y;

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
