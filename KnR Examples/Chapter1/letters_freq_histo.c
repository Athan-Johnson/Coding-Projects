#include <stdio.h>

/* This program creates a vertical histogram that shows the frequency of each letter in it's input 
 * This code is not well formatted for large amounts of characters but I don't think that can be fixed
 * in a reasonable amount of time, so I'm moving on. The first output is always a space so that's why
 * you can't see it */

#define NUM_CHARACTERS 128 // the number of characters you'd expect
#define NORAML_LETTERS_START 32

int main()
{
	int c, nc, most, index;
	int fullList[NUM_CHARACTERS] = {0}; // these are ints in case the code needs to be used on a file with an extened table

	nc = most = index = 0;
	// count how many of each letter are in the file
	while ((c = getchar()) != EOF)
	{
		++fullList[c];
		++nc;
	}

	// print the histogram
	// start by finding the most amount of times a certain letter is used
	for (int i = NORAML_LETTERS_START; i < NUM_CHARACTERS; ++i)
		if (fullList[i] > most)
			most = fullList[i];
	
	// next print out the histogram bars themselves

	// IMPORTANT: This assumes a left justification of at most 4 digits. If the amount of words in your file can be
	// on the order of 5 digits or higher then you should increase this. Unfortunatlely printf won't allow a constant to be
	// put in the %d statement so this must be changed manually. I also assume that no word will be longer than 99, so
	// everything is done around three spaces. 
	putchar('\n');
	for (int i = most; i > 0; --i) // outer loop, for each row
	{
		printf("%4d |", i); // This prints the y-axis labels
		for (int j = NORAML_LETTERS_START; j < NUM_CHARACTERS; ++j) // inner for loop, to print each collumn in the row
		{
			if (fullList[j] > 0)
			{
				if (fullList[j] < i) // the word isn't as long as the height we're at
					printf("   ");
				else if (fullList[j] == i) // the word is exactly as long as the height we're at, put a cap on it
					printf(" - ");
				else					// there are more letters than the height we're at, now just make the sides
					printf("| |");
			}
		}
		putchar('\n');
	}
	printf("      "); // this formats the x-axis line to be nicely in line with the y-axis
	for (int i = 0; i < index; ++i) // make the x-axis line
		printf("---");
	printf("\n      "); // this formats our numbers row, I don't know how to do this nicely except like this
	for (int i = NORAML_LETTERS_START; i < NUM_CHARACTERS; ++i)
	{
		if (fullList[i] > 0)
		{
			printf(" %c ", i);
		}
	}
	putchar('\n');
}
