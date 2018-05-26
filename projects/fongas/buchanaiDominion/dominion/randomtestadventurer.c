/*
* Name: Ashley Fong
* CS 362 - Assignment 4
* Filename: randomtestadventurer.c
* Description: Random test for 'adventurer' card
* Basic requirements of adventurer:
*	1. Current player reveals cards from deck until 2 treasure cards are revealed
*	2. Revealed treasure cards are placed in the player's hand
*	3. Other revealed cards are discarded
*	4. No state change should occur for other players
*	5. No state change should occur to the victory card piles and kingdom
*	card piles
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

	int handPos = 0;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int bonus = 0;
	int numPlayers = 2;
	int currentPlayer;
	int i = 0;
	int j = 0;
	int k = 0;

	int deckSize;
	int handSize;
	int fillDeckCard;
	int randomKC;
	int stateTreasure = 0;
	int testTreasure = 0;
	int discardedCopper = 0;
	int discardedSilver = 0;
	int discardedGold = 0;

	int numTreasureTestsPassed = 0;
	int numTreasureTestsFailed = 0;
	int numCopperTestsPassed = 0;
	int numCopperTestsFailed = 0;
	int numSilverTestsPassed = 0;
	int numSilverTestsFailed = 0;
	int numGoldTestsPassed = 0;
	int numGoldTestsFailed = 0;

	srand(time(NULL));

	for (i = 0; i < NUMITERATIONS; i++) {

		//initialize game
		initializeGame(numPlayers, kc, 1000, &state);

		//randomize deck size and hand count
		deckSize = rand() % (MAX_DECK + 1);
		handSize = rand() % (deckSize + 1);
		currentPlayer = 0;

		state.deckCount[0] = deckSize - handSize;
		state.handCount[0] = handSize;

		//manually simulate and fill the player's deck
		for (j = 0; j < numPlayers; j++) {
		
			for (k = 0; k < state.deckCount[j]; k++) {
			
				fillDeckCard = rand() % 16;

				if (fillDeckCard == 0) {
					state.deck[j][k] = copper;
				}
				else if (fillDeckCard == 1) {
					state.deck[j][k] = silver;
				}
				else if (fillDeckCard == 3) {
					state.deck[j][k] = gold;
				}
				else if (fillDeckCard == 4) {
					state.deck[j][k] = estate;
				}
				else if (fillDeckCard == 5) {
					state.deck[j][k] = duchy;
				}
				else if (fillDeckCard == 6) {
					state.deck[j][k] = province;
				}
				else {
					randomKC = rand() % 10;
					state.deck[j][k] = kc[randomKC];
				}

			}

		}

		//copy the game state to a test state
		memcpy(&test, &state, sizeof(struct gameState));

		//play Adventurer
		cardEffect(adventurer, choice1, choice2, choice3, &test, handPos, &bonus);

		//test 1: treasure card
		printf("\nAdventurer Test: Player's treasure card count\n");

		//state treasure count
		for (j = 0; j < state.handCount[currentPlayer]; j++) {
		
			if (state.hand[currentPlayer][j] == copper || state.hand[currentPlayer][j] == silver || state.hand[currentPlayer][j] == gold) {
				stateTreasure++;
			}
		}

		//test treasure count
		for (j = 0; j < test.handCount[currentPlayer]; j++) {

			if (test.hand[currentPlayer][j] == copper || test.hand[currentPlayer][j] == silver || test.hand[currentPlayer][j] == gold) {
				testTreasure++;
			}
		}

		if (testTreasure != stateTreasure + 2) {
			printf("\tFAILED: Expected treasure count: %d, actual treasure count: %d\n", stateTreasure, testTreasure);
			numTreasureTestsFailed++;
		}
		else {
			printf("\tPASSED: Treasure count correct.\n");
			numTreasureTestsPassed++;
		}


		//test discard pile - no treasure cards should be in discard pile
		for (j = 0; j < test.discardCount[currentPlayer]; j++) {
			
			if (test.discard[currentPlayer][j] == copper) {
				discardedCopper++;
			}
			else if (test.discard[currentPlayer][j] == silver) {
				discardedSilver++;
			}
			else if (test.discard[currentPlayer][j] == gold) {
				discardedGold++;
			}

		}

		//treasure cards in discard pile should all equal 0
		if (discardedCopper != 0) {
			printf("\tFAILED: Copper present in player's discard pile.\n");
			numCopperTestsFailed++;
		}
		else {
			printf("\tPASSED: No copper present in discard pile.\n");
			numCopperTestsPassed++;
		}

		if (discardedSilver != 0) {
			printf("\tFAILED: Silver present in player's discard pile.\n");
			numSilverTestsFailed++;
		}
		else {
			printf("\tPASSED: No silver present in discard pile.\n");
			numSilverTestsPassed++;
		}

		if (discardedGold != 0) {
			printf("\tFAILED: Gold present in player's discard pile.\n");
			numGoldTestsFailed++;
		}
		else {
			printf("\tPASSED: No gold present in discard pile.\n");
			numGoldTestsPassed++;
		}
	}

	printf("----------TESTING SUMMARY: ADVENTURER CARD----------\n");
	printf("Total number of test iterations: %d\n", NUMITERATIONS);
	printf("Total TREASURE tests PASSED: %d\n", numTreasureTestsPassed);
	printf("Total TREASURE tests FAILED: %d\n", numTreasureTestsFailed);
	printf("Total DISCARD-COPPER tests PASSED: %d\n", numCopperTestsPassed);
	printf("Total DISCARD-COPPER tests FAILED: %d\n", numCopperTestsFailed);
	printf("Total DISCARD-SILVER tests PASSED: %d\n", numSilverTestsPassed);
	printf("Total DISCARD-SILVER tests FAILED: %d\n", numSilverTestsFailed);
	printf("Total DISCARD-GOLD PASSED: %d\n", numGoldTestsPassed);
	printf("Total DISCARD-GOLD FAILED: %d\n", numGoldTestsFailed);

	return 0;
}