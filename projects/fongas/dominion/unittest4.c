/*
* Name: Ashley Fong
* CS 362 - Assignment 3
* Filename: unittest4.c
* Description: Unit test for 'gainCard' function
* Basic requirements of function gainCard():
*	1. Adds the passed in card into one of 3 piles for a player
*	2. If the flag = 0, the passed in card is added to the discard pile
*	3. If the flag = 1, the passed in card is added to the player's deck
*	4. If the flag = 2, the passed in card is added to the player's hand
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

	int numPlayers = 2;
	int player1 = 0;

	//begin unit tests
	printf("\n***Unit Tests: gainCard()***\n");

	//initialize game - test 1 - flag = 0
	initializeGame(numPlayers, kc, 1000, &state);

	//copy the game state to a test state
	memcpy(&test, &state, sizeof(struct gameState));

	//call gainCard - 'estate' card will be used for testing - flag = 0 (discard pile)
	gainCard(estate, &test, 0, 0);

	//test: discard 
	printf("\ngainCard() Test 1: discard - tests whether a card is added to a player's discard pile\n");
	if (test.discardCount[player1] != state.discardCount[player1] + 1) {
		printf("\tFailed: Expected number of cards in discard pile: %d, actual number of cards in discard pile: %d", state.discardCount[player1] + 1, test.discardCount[player1]);
	}
	else {
		printf("\tPassed: Discard pile count correct\n");
	}

	//reinitialize game - test 2 - flag = 1
	initializeGame(numPlayers, kc, 1000, &state);

	//copy the game state to a test state
	memcpy(&test, &state, sizeof(struct gameState));

	//call gainCard - 'estate' card will be used for testing - flag = 1 (deck pile)
	gainCard(estate, &test, 1, 0);

	//test: deck count 
	printf("\ngainCard()Test 2: deck card count - tests whether a card is added to a player's deck\n");
	if (test.deckCount[player1] != state.deckCount[player1] + 1) {
		printf("\tFailed: Expected deck count: %d, actual deck count: %d\n", state.deckCount[player1] + 1, test.deckCount[player1]);
	}
	else {
		printf("\tPassed: Deck count correct\n");
	}

	//reinitialize game - test 2 - flag = 2
	initializeGame(numPlayers, kc, 1000, &state);

	//copy the game state to a test state
	memcpy(&test, &state, sizeof(struct gameState));

	//call gainCard - 'estate' card will be used for testing - flag = 2 (hand pile)
	gainCard(estate, &test, 2, 0);

	//test: hand card count
	printf("\ngainCard()Test 1: hand card count - tests whether a card is added to player's hand\n");
	if (test.handCount[player1] != state.handCount[player1] + 1) {
		printf("\tFailed: Expected card hand count: %d, actual card hand count: %d\n", state.handCount[player1] + 1, test.handCount[player1]);
	}
	else {
		printf("\tPassed: Hand count correct.\n");
	}

	return 0;

}