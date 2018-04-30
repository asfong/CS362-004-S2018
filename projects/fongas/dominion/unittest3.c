/*
* Name: Ashley Fong
* CS 362 - Assignment 3
* Filename: unittest3.c
* Description: Unit test for 'updateCoins' function
* Basic requirements of function updateCoins():
*	1. Adds coins for each Treasure card in a player's hand
*	2. A copper Treasure card is worth 1 coin
*	3. A silver Treasure card is worth 2 coins
*	4. A gold Treasure card is worth 3 coins
*	5. Bonus coins are added when available
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
	int initialCoinCount = 0;

	//begin unit tests
	printf("\n***Unit Tests: updateCoins()***\n");

	//initialize game - test 1 - copper: worth 1 coin
	initializeGame(numPlayers, kc, 1000, &state);

	//copy the game state to a test state
	memcpy(&test, &state, sizeof(struct gameState));

	//manually similate a player's hand to test copper
	test.hand[player1][0] = copper;
	test.hand[player1][1] = adventurer;
	test.hand[player1][2] = council_room;
	test.hand[player1][3] = feast;
	test.hand[player1][4] = gardens;

	//call updateCoins - value of copper = 1
	updateCoins(player1, &test, 0);
	printf("\nupdateCoins() Test 1: testing whether coppers are calculated correctly\n");
	if (test.coins == initialCoinCount + 1) {
		printf("\tPassed: Expected number of coins: 1, actual number of coins: %d \n", test.coins);
	}
	else {
		printf("\nFailed: Expected number of coins: 1, actual number of coins: %d \n", test.coins);
	}

	//initialize game - test 2 - silver: worth 2 coins
	initializeGame(numPlayers, kc, 1000, &state);

	//copy the game state to a test state
	memcpy(&test, &state, sizeof(struct gameState));

	//manually similate a player's hand to test silver
	test.hand[player1][0] = silver;
	test.hand[player1][1] = adventurer;
	test.hand[player1][2] = council_room;
	test.hand[player1][3] = feast;
	test.hand[player1][4] = gardens;

	//call updateCoins - value of silver = 2
	updateCoins(player1, &test, 0);
	printf("\nupdateCoins() Test 2: testing whether silvers are calculated correctly\n");
	if (test.coins == initialCoinCount + 2) {
		printf("\tPassed: Expected number of coins: 2, actual number of coins: %d \n", test.coins);
	}
	else {
		printf("\nFailed: Expected number of coins: 2, actual number of coins: %d \n", test.coins);
	}

	//initialize game - test 3 - gold: worth 3 coins
	initializeGame(numPlayers, kc, 1000, &state);

	//copy the game state to a test state
	memcpy(&test, &state, sizeof(struct gameState));

	//manually similate a player's hand to test gold
	test.hand[player1][0] = gold;
	test.hand[player1][1] = adventurer;
	test.hand[player1][2] = council_room;
	test.hand[player1][3] = feast;
	test.hand[player1][4] = gardens;

	//call updateCoins - value of copper = 3
	updateCoins(player1, &test, 0);
	printf("\nupdateCoins() Test 3: testing whether golds are calculated correctly\n");
	if (test.coins == initialCoinCount + 3) {
		printf("\tPassed: Expected number of coins: 3, actual number of coins: %d \n", test.coins);
	}
	else {
		printf("\nFailed: Expected number of coins: 3, actual number of coins: %d \n", test.coins);
	}

	//initialize game - test 4 - bonus: increments coins by passed argument - for testing, 1 will be passed
	initializeGame(numPlayers, kc, 1000, &state);

	//copy the game state to a test state
	memcpy(&test, &state, sizeof(struct gameState));

	//manually similate a player's hand without any Treasure cards
	test.hand[player1][0] = smithy;
	test.hand[player1][1] = adventurer;
	test.hand[player1][2] = council_room;
	test.hand[player1][3] = feast;
	test.hand[player1][4] = gardens;

	//call updateCoins - value of test bonus amount: 1
	updateCoins(player1, &test, 1);
	printf("\nupdateCoins() Test 4: testing whether bonuses are calculated correctly\n");
	if (test.coins == initialCoinCount + 1) {
		printf("\tPassed: Expected number of coins: 1, actual number of coins: %d \n", test.coins);
	}
	else {
		printf("\nFailed: Expected number of coins: 1, actual number of coins: %d \n", test.coins);
	}

	return 0;

}