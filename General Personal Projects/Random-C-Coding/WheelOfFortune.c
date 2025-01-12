#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define LONGEST_POSSIBLE_WORD 50
#define MOST_POSSIBLE_CHARACTERS 128

struct answers {
	char person[LONGEST_POSSIBLE_WORD];
	char place[LONGEST_POSSIBLE_WORD];
	char thing[LONGEST_POSSIBLE_WORD];
};


// this is going to be a basic wheel of fortune program
int main() {

	struct answers a;
	strcpy(a.person, "Joe Mama");
	strcpy(a.place, "Virginia");
	strcpy(a.thing, "communism");

	printf("Welcome to the Wheel of Fortune!\n");

	// pick the answer
	int random_index = rand() % 3;
	char word[LONGEST_POSSIBLE_WORD] = "";
	// Access the chosen field based on the random index
    	switch (random_index) {
		case 0:
        		strcpy(word, a.person);
        		break;
        	case 1:
            		strcpy(word, a.place);
            		break;
        	case 2:
            		strcpy(word, a.thing);
            		break;
        	default:
            		printf("Error: Invalid random index chosen when chosing a word.\n");
    }

	bool won = false;
	char guessed_letters[MOST_POSSIBLE_CHARACTERS] = ""; // initialize empty list of guesses
	int num_guesses = 0;
	strcpy(guessed_letters, "\n");

	while (!won) {
		printf("What you know:\n");

		for (int i = 0; i < strlen(word); i++) {
			if (strchr(guessed_letters, word[i])) { // check if the character is guessed
				printf("%c", word[i]);
			}
			else if (word[i] == ' ') { // just print spaces normally
				printf(" ");
			}
			else { // print underscores to show what still remains to be guessed
				printf("_");
			}
		}

		printf("\n\nGuess a Letter!\n>>");
		char guess;
		scanf(" %c", &guess);
		
		if (!strchr(guessed_letters, guess)) {
			guessed_letters[num_guesses] = guess;
			num_guesses++;
			guessed_letters[num_guesses] = "\0";
		}
		else {
			printf("\n\nWhoops! That's already been guessed. Looks like you'll just be wasting this turn!\n");
		}

		won = true;
		for (int i = 0; i < strlen(word); i++) {
			if (word[i] != ' ' && !strchr(guessed_letters, word[i])) {
				won = false;
				break;
			}
		}
	}

	printf("\n\nCongrats! You've won!\n\n");
}
