#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_CARDS 12 // seven unique cards + three free point cards + double points card + second life card

struct Player {
	int points;
	int current_cards[MAX_CARDS];
	int has_double;
}


int main() {
	// local variables
	int num_players = 0;
	int won = FALSE;

	printf("Welcome to Pick Seven! The rules are simple, so we don't need to go over them.\n");
	printf("Please enter the number of players: \n");

	// check the number of players entered
	if (scanf("%d", &num_players) != 1) {
		printf("Invalid input!\n");
		return 0;
	}

	// create each player
	struct Player *players = malloc(num_players * sizeof(struct Player));
	for (int i = 0; i < num_players; i++){
		players[i].points = 0;
		players[i].has_double = FALSE;
	}

	// play the game
	while (!won) {
		
	}


	return 0;
}
