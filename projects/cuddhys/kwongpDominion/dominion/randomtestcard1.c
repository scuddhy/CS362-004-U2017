/***************************************************
 * Author: Shawn Cuddhy
 * Description: Random tester for the village card
****************************************************/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int villageFuncTwo(int currentPlayer, struct gameState* state, int handPos){
	int arr[3] = {0, 1, 2};
	int i;
	int x;

	//+1 Card
	drawCard(currentPlayer, state);

	//+2 Actions
	state->numActions = state->numActions + 2;

	for(i = 0; i < 4; i++){
		x += arr[i];
	}

	//discard played card from hand
	discardCard(handPos, currentPlayer, state, 0);
	return 0;
}






int main(int argc, char* argv[]){
	srand(time(NULL));
	int i = 0;
	int seed = 1000;
	int loopCt = 100;
	int numPlayer =rand() % MAX_PLAYERS;
	int passed = 1;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel,
		smithy, village, baron, great_hall};
	struct gameState* state = newGame();
	printf("Executing Village Func test....\n");
	
	
	//loop through test, random value for numPlayer and current Player 
	for(i = 0; i < loopCt; i++){
		initializeGame(numPlayer, k, seed, state);
		int currentPlayer = rand()% numPlayer;
		printf("Executing test# %d\n", i);
		int cardBefore = state->handCount[currentPlayer];
		int actionBefore = state->numActions;
		villageFuncTwo(currentPlayer, state, 1);
		int cardAfter = state->handCount[currentPlayer];
		int actionAfter = state->numActions;
		int cardSum = cardAfter - cardBefore;
		int actionSum = actionAfter - actionBefore;

		
		if(cardSum != 0) {
			passed = 0;
			printf("number of cards is wrong\n");
		}
		if(actionSum != 2) {
			passed = 0;
			printf("action sum is wrong\n");
		}

	}
	
	//return results of the test	
	if(passed == 1){
		printf("Test passed!\n");
	}
	else{
		printf("Test failed!\n");
	}

	return 0;

}


