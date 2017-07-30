/***************************************
 *Author : Shawn Cuddhy
 *Description: random tester for adventurer card
****************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int adventurerFuncTwo(int currentPlayer, struct gameState* state){
	int drawntreasure = 0;
	int cardDrawn;
	int temphand[MAX_HAND];
	int z = 0;

	while(drawntreasure<2){
		z = 99;
		if(state->deckCount[currentPlayer]<1){
			shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
		if(cardDrawn == copper || cardDrawn == silver || cardDrawn == gold){
			drawntreasure++;
		}
		else{
			temphand[z] = cardDrawn;
			state->handCount[currentPlayer]--;
			z++;
		}
	}
	while(z-1>=0){
		state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1];
		z=z-1;
	}
	return 0;

}


int main(int argc, char* argv[]){
	srand(time(NULL));
	//function test call
	printf("Executing random adventureFunc Testing...\n");

	int currentPlayer = 1;
	struct gameState* state = newGame();
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel,
		smithy, village, baron, great_hall};
	int passed = 1;
	int x;
	int randShuffle;
	int i;
	int loopCt = 100;

	initializeGame(MAX_PLAYERS, k, 1000, state);

	//randomize whether deck shuffle happens or not
	//randomize the player that actually executes the action
	//check that the function runs correctly;
	for(i = 0; i < loopCt; i++){
		printf("Loop count %d: \n", i);
		currentPlayer = rand() % MAX_PLAYERS;
		randShuffle = rand() % 1;
		state->deckCount[currentPlayer] = randShuffle;
		x = adventurerFuncTwo(currentPlayer, state);
		if (x != 0) {
			passed = 0;
			printf("Error when currentPlayer = %d, deck shuffle = %d \n", currentPlayer, randShuffle);
		}

	}

	if (passed == 1) { 
		printf("AdventureFunc random test passed!\n");
	}
	
	free(state);
	return 0;

}


