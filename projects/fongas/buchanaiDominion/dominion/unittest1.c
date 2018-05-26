/*
* Name: Ashley Fong
* CS 362 - Assignment 3
* Filename: unittest1.c
* Description: Unit test for 'isGameOver' function
* Basic requirements of function isGameOver():
	1. If the stack of Province cards is empty, the game ends with returning the
		the integer 1
	2. If 3 supply piles are at 0, the game ends with returning the integer 1
	3. Otherwise, returns the integer 0
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
	int result;

	//initialize game - test 1
	initializeGame(numPlayers, kc, 1000, &state);

	//begin unit tests
	printf("\n***Unit Tests: isGameOver()***\n");

	//copy the game state to a test state
	memcpy(&test, &state, sizeof(struct gameState));

	//test 1 - Province cards
	printf("\nisGameOver() Test 1: testing whether the game ends when the stack of Province cards is empty\n");
	test.supplyCount[province] = 0;
	result = isGameOver(&test);

	if (result != 1) {
		printf("\tFailed: The returned result is %d - the game is not over.\n", result);
	}
	else
	{
		printf("\tPassed: The returned result is %d - the game is over.\n", result);
	}

	//initialize game - test 2
	initializeGame(numPlayers, kc, 1000, &state);

	//copy the game state to a test state
	memcpy(&test, &state, sizeof(struct gameState));

	printf("\nisGameOver() Test 2: testing whether the game ends when 3 supply piles are at 0\n");
	test.supplyCount[copper] = 0;
	test.supplyCount[silver] = 0;
	test.supplyCount[estate] = 0;
	result = isGameOver(&test);

	if (result != 1) {
		printf("\tFailed: The returned result is %d - the game is not over.\n", result);
	}
	else
	{
		printf("\tPassed: The returned result is %d - the game is over.\n", result);
	}

	return 0;

}