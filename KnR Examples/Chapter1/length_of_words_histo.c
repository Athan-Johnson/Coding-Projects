#include <stdio.h>

/* This program creates a vertical histogram that shows the frequency
 * of different lengths of words that it is passed to as input */

#define IN 1 // in a word
#define OUT 0 // outside of a word
#define MIN_LENGTH 1 // this is easier to remember then adding one or starting i at one or sometimes
#define MAX_LENGTH 20 // the most amount of characters a word can have in the file, minus one for array indexing reasons.
						// Increasing this too much really messes with how the graph looks

int main()
{
	int c, state, nw, lgth, most;
	int word_lengths[MAX_LENGTH] = {0};

	nw = lgth = most = 0;
	// count how many words of each length are in the file
	while ((c = getchar()) != EOF)
	{
		// checking for words is a little more complicated, and is done here:
		if (c == ' ' || c == '\n' || c == '\t') // outside a word
		{
			if (state == IN) // we just left a word
				++word_lengths[lgth]; // this is because we can't have a zero length word, so we'd otherwise waste space
			state = OUT;
			lgth = 0;
		}
		else if (state == OUT) // at the first letter of a word
		{
			state = IN;
			++nw;
			++lgth;
		}
		else // we are in a word and past the first letter
			++lgth;
	}

	// print the histogram
	// start by finding the most amount of times a certain length of word is used
	for (int i = MIN_LENGTH; i < MAX_LENGTH; ++i)
		if (word_lengths[i] > most)
			most = word_lengths[i];
	
	// next print out the histogram bars themselves

	// IMPORTANT: This assumes a left justification of at most 4 digits. If the amount of words in your file can be
	// on the order of 5 digits or higher then you should increase this. Unfortunatlely printf won't allow a constant to be
	// put in the %d statement so this must be changed manually. I also assume that no word will be longer than 99, so
	// everything is done around four spaces. 
	putchar('\n');
	for (int i = most; i > 0; --i) // outer loop, for each row
	{
		printf("%4d |", i); // This prints the y-axis labels
		for (int j = MIN_LENGTH; j < MAX_LENGTH; ++j) // inner for loop, to print each collumn in the row
		{
			if (word_lengths[j] < i) // the word isn't as long as the height we're at
				printf("    ");
			else if (word_lengths[j] == i) // the word is exactly as long as the height we're at, put a cap on it
				printf(" -- ");
			else					// the the word is longer than the height we're at, we've capped it now just make the sides
				printf("|%2d|", j);
		}
		putchar('\n');
	}
	printf("      "); // this formats the x-axis line to be nicely in line with the y-axis
	for (int i = MIN_LENGTH; i < MAX_LENGTH; ++i) // make the x-axis line
		printf("----");
	printf("\n      "); // this formats our numbers row
	for (int i = MIN_LENGTH; i < MAX_LENGTH; ++i)
		printf(" %2d ", i);
	putchar('\n');
}
