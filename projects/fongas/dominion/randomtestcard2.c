/*
* Name: Ashley Fong
* CS 362 - Assignment 4
* Filename: randomtestcard2.c
* Description: Random test for 'great_hall' card
* Basic requirements of great_hall:
*	1. Current player should receive +1 card
*	2. +1 cards should come from the player's own deck pile
*	3. Current player should receive +1 actions
*	4. No state change should occur to the victory card piles and kingdom
*		card piles
*	5. The card is discarded
*	6. At the end of the game, it is worth 1 victory point
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define NUMITERATIONS	1000

int main() {

	//kingdom cards
	int kc[10] = { adventurer, council_room, feast, gardens, mine,
		remodel, smithy, village, baron, great_hall };

	//original gameState
	struct gameState state;
	//test gameState
	struct gameState test;

	int cardsDrawn = 1;
	int cardsDiscarded = 1;
	int handPos = 0;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int bonus = 0;
	int numPlayers = 2;
	int currentPlayer;
	int i = 0;

	int deckSize;
	int handSize;

	int numHandCountTestsPassed = 0;
	int numHandCountTestsFailed = 0;
	int numDeckCountTestsPassed = 0;
	int numDeckCountTestsFailed = 0;
	int numActionsTestsPassed = 0;
	int numActionsTestsFailed = 0;
	int numDiscardTestsPassed = 0;
	int numDiscardTestsFailed = 0;

	srand(time(NULL));

	for (i = 0; i < NUMITERATIONS; i++) {

		//initialize game
		initializeGame(numPlayers, kc, 1000, &state);

		//randomize deck size and hand cout
		deckSize = rand() % (MAX_DECK + 1);
		handSize = rand() % (deckSize + 1);
		currentPlayer = 0;

		state.deckCount[0] = deckSize - handSize;
		state.handCount[0] = handSize;

		//randomize numActions
		state.numActions = rand() % 10;

		handPos = state.hand[currentPlayer][state.handCount[currentPlayer] - 1];

		//copy the game state to a test state
		memcpy(&test, &state, sizeof(struct gameState));

		//play Great Hall
		cardEffect(great_hall, choice1, choice2, choice3, &test, handPos, &bonus);

		//test 1: hand card count
		printf("\nGreat Hall Test: Player's hand card count\n");
		if (test.handCount[currentPlayer] != state.handCount[currentPlayer] + cardsDrawn - cardsDiscarded) {
			printf("\tFAILED: Expected card hand count: %d, actual card hand count: %d\n", state.handCount[currentPlayer] + cardsDrawn - cardsDiscarded, test.handCount[currentPlayer]);
			numHandCountTestsFailed++;
		}
		else {
			printf("\tPASSED: Card hand count correct.\n");
			numHandCountTestsPassed++;
		}

		//test 2: deck count 
		printf("\nGreat Hall Test: Player's deck card count\n");
		if (test.deckCount[currentPlayer] != state.deckCount[currentPlayer] - cardsDrawn) {
			printf("\tFAILED: Expected deck count: %d, actual deck count: %d\n", state.deckCount[currentPlayer] - cardsDrawn, test.deckCount[currentPlayer]);
			numDeckCountTestsFailed++;
		}
		else {
			printf("\tPASSED: Deck count correct\n");
			numDeckCountTestsPassed++;
		}

		//test 3: +1 numActions
		printf("\nGreat Hall Test: Player's number of actions\n");
		if (test.numActions != state.numActions + 1) {
			printf("\tFAILED: Expected number of actions: %d, actual number of actions: %d\n", state.numActions + 1, test.numActions);
			numActionsTestsFailed++;
		}
		else {
			printf("\tPASSED: Number of actions correct\n");
			numActionsTestsPassed++;
		}

		//test 4: tests whether card is discarded after play
		printf("\nGreat Hall Test: Player's discard pile\n");
		if (test.discardCount[currentPlayer] != state.discardCount[currentPlayer]) {
			printf("\tFAILED: Expected number of cards in discard pile: %d, actual number of cards in discard pile: %d", state.discardCount[currentPlayer], test.discardCount[currentPlayer]);
			numDiscardTestsFailed++;
		}
		else {
			printf("\tPASSED: Discard pile count correct\n");
			numDiscardTestsPassed++;
		}

	}

	printf("----------TESTING SUMMARY: GREAT HALL CARD----------\n");
	printf("Total number of test iterations: %d\n", NUMITERATIONS);
	printf("Total HAND COUNT tests PASSED: %d\n", numHandCountTestsPassed);
	printf("Total HAND COUNT tests FAILED: %d\n", numHandCountTestsFailed);
	printf("Total DECK COUNT tests PASSED: %d\n", numDeckCountTestsPassed);
	printf("Total DECK COUNT tests FAILED: %d\n", numDeckCountTestsFailed);
	printf("Total ACTIONS tests PASSED: %d\n", numActionsTestsPassed);
	printf("Total ACTIONS tests FAILED: %d\n", numActionsTestsFailed);
	printf("Total DISCARD tests PASSED: %d\n", numDiscardTestsPassed);
	printf("Total DISCARD tests FAILED: %d\n", numDiscardTestsFailed);

	return 0;
}
