/* This program takes in x and n and returns the value of the integer x rotated to the right by n bit positions
 * Author: Athan Johnson
 * Created: 1/22/2025
 * Modified:
 */

#include <stdio.h>

#define X 0b11101
#define N 1

unsigned rightRot(unsigned x, int n);
void printBinary(unsigned x);

int main()
{
	unsigned temp = rightRot(X, N);
	printf("Binary: ");
	printBinary(temp);
	printf("Actual number: %u\n", temp);
	return 0;
}

unsigned rightRot(unsigned x, int n)
{
	// declare variables
	unsigned right_end = x & ~(~0 << n); // this gives us the right end of x
	int length_of_x = 0;
	
	int temp_x = x; // this is going to get deleted as we calculate the length of x
	while (temp_x != 0)
	{
		length_of_x++;
		temp_x = temp_x >> 1;
	}

	right_end = right_end << length_of_x-n;

	x = x >> n; // this rotates x to the right
	return x | right_end;
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
