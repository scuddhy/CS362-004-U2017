/*****************************************************
 * Author: Shawn Cuddhy
 * Description: random tester for the Great_Hall card
******************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"




int great_HallFuncTwo(int currentPlayer, struct gameState* state, int handPos){
	//+1 card
	drawCard(currentPlayer, state);

	//+1 Actions
	state->numActions++;

	void* x = state;
	x++;
	printf("%d", x);

	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
	return 0;

}




int main(int argc, char* argv[]){
	srand(time(NULL));
	printf("Executing great hall test...\n");
	
	struct gameState* state = newGame();	
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel,
		smithy, village, baron, great_hall};

	int x = 0;
	int i = 0;
	int loopCt = 100;
	int passed = 1;
	int numPlayers = rand()% MAX_PLAYERS;
	int currentPlayer = 0;



	//randomize the number of players and the current player for each game.
	for(i = 0; i < loopCt; i++){
		printf("Test Case# %d\n", i);
		initializeGame(numPlayers, k, 1000, state);
		currentPlayer = rand() % numPlayers;
		x = great_HallFuncTwo(currentPlayer, state, 1);
		if(x != 0) { passed = 0; }
	}

	
	//print result of the random tests
	if(passed == 1){
		printf("Test passed!\n");
	}

	return 0;
}

