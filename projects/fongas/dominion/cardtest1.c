/*
* Name: Ashley Fong
* CS 362 - Assignment 3
* Filename: cardtest1.c
* Description: Unit test for 'smithy' card
* Basic requirements of smithy:
*	1. Current player should receive exactly 3 cards
*	2. 3 cards should come from the player's own deck pile
*	3. No state change should occur for other players
*	4. No state change should occur to the victory card piles and kingdom
*		card piles
*	5. The smithy card is discarded
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {

	//kingdom cards
	int kc[10] = { adventurer, council_room, feast, gardens, mine, 
		remodel, smithy, village, baron, great_hall };

	//original gameState
	struct gameState state;
	//test gameState
	struct gameState test;

	int cardsDrawn = 3;
	int cardsDiscarded = 1;
	int handPos = 0;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int bonus = 0;
	int numPlayers = 2;
	int player1 = 0;
	int player2 = 1;

	//counter for kingdom cards
	int i = 0;

	//initialize game
	initializeGame(numPlayers, kc, 1000, &state);

	//begin card test
	printf("\n***Card Tests: Smithy***\n");

	//copy the game state to a test state
	memcpy(&test, &state, sizeof(struct gameState));

	cardEffect(smithy, choice1, choice2, choice3, &test, handPos, &bonus);

	//test 1: hand card count
	printf("\nSmithy Test 1: Player1's hand card count - tests whether Player1 correctly obtains 3 additional cards\n");
	if (test.handCount[player1] != state.handCount[player1] + cardsDrawn - cardsDiscarded) {
		printf("\tFailed: Expected card hand count: %d, actual card hand count: %d\n", state.handCount[player1] + cardsDrawn - cardsDiscarded, test.handCount[player1]);
	}
	else {
		printf("\tPassed: Card hand count correct.\n");
	}

	//test 2: deck count 
	printf("\nSmithy Test 2: Player1's deck card count - tests whether Player1's deck decreases by 3\n");
	if (test.deckCount[player1] != state.deckCount[player1] - cardsDrawn) {
		printf("\tFailed: Expected deck count: %d, actual deck count: %d\n", state.deckCount[player1] - cardsDrawn, test.deckCount[player1]);
	}
	else {
		printf("\tPassed: Deck count correct\n");
	}

	//test: player2's hand card count
	printf("\nSmithy Test 3: Player2's hand card count - tests to ensure no state change occurs for Player2\n");
	if (test.handCount[player2] != state.handCount[player2]) {
		printf("\tFailed: Expected hand card count%d, actual hand card count %d\n", state.handCount[player2], test.handCount[player2]);
	}
	else {
		printf("\tPassed: State of Player2's hand card count is unchanged\n");
	}

	//test: player2's deck count
	printf("\nSmithy Test 4: Player2's deck card count - tests to ensure no state change occurs for Player2\n");
	if (test.deckCount[player2] != state.deckCount[player2]) {
		printf("\tFailed: Expected deck count %d, actual deck count %d\n", state.deckCount[player2], test.deckCount[player2]);
	}
	else {
		printf("\tPassed: State of Player 2's deck count is unchanged\n");
	}

	//tests: state changes in the victory card piles
	printf("\nSmithy Test 5: state of Estate victory cards\n");
	if (test.supplyCount[estate] != state.supplyCount[estate]) {
		printf("\tFailed: Expected number of Estate victory cards %d, actual number of Estate victory cards %d\n", state.supplyCount[estate], test.supplyCount[estate]);
	}
	else {
		printf("\tPassed: State of Estate victory cards is unchanged\n");
	}

	printf("\nSmithy Test 6: state of Duchy victory cards\n");
	if (test.supplyCount[duchy] != state.supplyCount[duchy]) {
		printf("\tFailed: Expected number of Duchy victory cards %d, actual number of Duchy victory cards %d\n", state.supplyCount[duchy], test.supplyCount[duchy]);
	}
	else {
		printf("\tPassed: State of Duchy victory cards is unchanged\n");
	}

	printf("\nSmithy Test 7: state of Province victory cards\n");
	if (test.supplyCount[province] != state.supplyCount[province]) {
		printf("\tFailed: Expected number of Provice victory cards %d, actual number of Province victory cards %d\n", state.supplyCount[province], test.supplyCount[province]);
	}
	else {
		printf("\tPassed: State of Province victory cards is unchanged\n");
	}

	//test: state change in kingdom cards - 10 piles
	printf("\nSmithy Test 8: state of Kingdom card piles\n");
	for (i = 1; i < 11; i++) {

		if (test.supplyCount[kc[i]] != state.supplyCount[kc[i]]) {
			printf("\tFailed: State change in Kingdom card pile #%d\n", i);
		}
		else {
			printf("\tPassed: State of Kingdom card pile #%d is unchanged\n", i);
		}
	}

	//test: discard 
	printf("\nSmithy Test 9: discard - tests whether the smithy card is discarded after play\n");
	if (test.discardCount[player1] != state.discardCount[player1]) {
		printf("\tFailed: Expected number of cards in discard pile: %d, actual number of cards in discard pile: %d", state.discardCount[player1], test.discardCount[player1]);
	}
	else {
		printf("\tPassed: Discard pile count correct\n");
	}

	return 0;
}