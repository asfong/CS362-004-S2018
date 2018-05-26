/*
* Name: Ashley Fong
* CS 362 - Assignment 3
* Filename: cardtest2.c
* Description: Unit test for 'adventurer' card
* Basic requirements of adventurer:
*	1. Current player reveals cards from deck until 2 treasure cards are revealed
*	2. Revealed treasure cards are placed in the player's hand
*	3. Other revealed cards are discarded
*	4. No state change should occur for other players
*	5. No state change should occur to the victory card piles and kingdom
*	card piles
* Note: commented out below display several attempts to test the 'drawnTreasure' portion 
* of the Adventurer card -- could not debug in time -- both versions caused 
* segmentation faults (core dumped) when tested on FLIP. I will need to examine further.
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

	//counter for drawn treasure cards
	//int j = 0;

	//to count drawn treasure cards
	//int testDrawnTreasure = 0;
	//int stateDrawnTreasure = 0;

	//initialize game
	initializeGame(numPlayers, kc, 1000, &state);

	//begin card test
	printf("\n***Card Tests: Adventurer***\n");

	//copy the game state to a test state
	memcpy(&test, &state, sizeof(struct gameState));

	/*
	//manually similate a deck and hand for player1
	test.whoseTurn = player1;

	test.deck[player1][0] = gold;
	test.deck[player1][1] = gold;
	test.deck[player1][2] = smithy;
	test.deck[player1][3] = feast;
	test.deck[player1][4] = silver;
	test.deck[player1][5] = council_room;
	test.deck[player1][6] = copper;
	test.deck[player1][7] = steward;


	test.deckCount[player1] = 8;

	test.hand[player1][0] = adventurer;
	test.hand[player1][1] = estate;
	test.hand[player1][2] = mine;
	test.hand[player1][3] = smithy;
	test.hand[player1][4] = village;

	test.handCount[player1] = 5;

	//pre-cardEffect card counts
	int preHandCount = test.handCount[player1];
	int preDeckCount = test.deckCount[player1];

	//call cardEffect
	cardEffect(adventurer, choice1, choice2, choice3, &test, handPos, &bonus);

	//post-cardEffect card counts
	int postHandCount = test.handCount[player1];
	int postDeckCount = test.deckCount[player1];

	//test - player1's hand card count
	printf("\nAdventurer Test 1: tests whether 2 additional cards, given the simulated deck, is added to the player's hand\n");
	if (postHandCount != preHandCount + 2) {
		printf("\tFailed: Expected number of cards in hand: %d, actual number of cards in hand: %d\n", preHandCount + 2, postHandCount);
	}
	else {
		printf("\tPassed: Expected number of cards in hand: %d, actual number of cards in hand: %d\n", preHandCount + 2, postHandCount);
	}

	//test - player1's deck count
	printf("\nAdventurer Test 2: tests whether, given the simulated deck, 3 cards are removed from the player's deck \n");
	if (postDeckCount != preDeckCount - 3) {
		printf("\tFailed: Expected number of cards in deck: %d, actual number of cards in deck: %d\n", preDeckCount - 3, postDeckCount);
	}
	else {
		printf("\tPassed: Expected number of cards in deck: %d, actual number of cards in deck: %d\n", preDeckCount - 3, postDeckCount);
	}

	*/

	/*
	for (j = 0; j < state.handCount[player1]; j++) {
		if (state.hand[player1] == copper || silver || gold) {
			stateDrawnTreasure++;
		}
	}
	*/

	/*
	//count up the drawn treasure in gameState state and gameState test
	for (j = 0; j < test.handCount[player1]; j++) {
		if (test.hand[player1] == copper || silver || gold) {
			testDrawnTreasure++;
		}
	}

	//test: increase of +2 treasure cards
	printf("\nAdventurer Test 1: Player1's treasure card count - tests to ensure +2 increase in treasure cards for Player1\n");
	if (testDrawnTreasure != stateDrawnTreasure + 2) {
		printf("\tFailed: Expected number of treasure cards: %d, actual number of treasure cards: %d, \n", stateDrawnTreasure, testDrawnTreasure);
	}
	else {
		printf("\tPassed: Expected number of treasure cards: %d, actual number of treasure cards: %d, \n", stateDrawnTreasure, testDrawnTreasure);
	}
	*/

	//call cardEffect
	cardEffect(adventurer, choice1, choice2, choice3, &test, handPos, &bonus);
	
	//test: player2's hand card count
	printf("\nAdventurer Test 1: Player2's hand card count - tests to ensure no state change occurs for Player2\n");
	if (test.handCount[player2] != state.handCount[player2]) {
		printf("\tFailed: Expected hand card count%d, actual hand card count %d\n", state.handCount[player2], test.handCount[player2]);
	}
	else {
		printf("\tPassed: State of Player2's hand card count is unchanged\n");
	}

	//test: player2's deck count
	printf("\nAdventurer Test 2: Player2's deck card count - tests to ensure no state change occurs for Player2\n");
	if (test.deckCount[player2] != state.deckCount[player2]) {
		printf("\tFailed: Expected deck count %d, actual deck count %d\n", state.deckCount[player2], test.deckCount[player2]);
	}
	else {
		printf("\tPassed: State of Player 2's deck count is unchanged\n");
	}

	//tests: state changes in the victory card piles
	printf("\nAdventurer Test 3: state of Estate victory cards\n");
	if (test.supplyCount[estate] != state.supplyCount[estate]) {
		printf("\tFailed: Expected number of Estate victory cards %d, actual number of Estate victory cards %d\n", state.supplyCount[estate], test.supplyCount[estate]);
	}
	else {
		printf("\tPassed: State of Estate victory cards is unchanged\n");
	}

	printf("\nAdventurer Test 4: state of Duchy victory cards\n");
	if (test.supplyCount[duchy] != state.supplyCount[duchy]) {
		printf("\tFailed: Expected number of Duchy victory cards %d, actual number of Duchy victory cards %d\n", state.supplyCount[duchy], test.supplyCount[duchy]);
	}
	else {
		printf("\tPassed: State of Duchy victory cards is unchanged\n");
	}

	printf("\nAdventurer Test 5: state of Province victory cards\n");
	if (test.supplyCount[province] != state.supplyCount[province]) {
		printf("\tFailed: Expected number of Provice victory cards %d, actual number of Province victory cards %d\n", state.supplyCount[province], test.supplyCount[province]);
	}
	else {
		printf("\tPassed: State of Province victory cards is unchanged\n");
	}

	//test: state change in kingdom cards - 10 piles
	printf("\nAdventurer Test 6: state of Kingdom card piles\n");
	for (i = 1; i < 11; i++) {

		if (test.supplyCount[kc[i]] != state.supplyCount[kc[i]]) {
			printf("\tFailed: State change in Kingdom card pile #%d\n", i);
		}
		else {
			printf("\tPassed: State of Kingdom card pile #%d is unchanged\n", i);
		}
	}

	return 0;

}