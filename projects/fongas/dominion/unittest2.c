/*
* Name: Ashley Fong
* CS 362 - Assignment 3
* Filename: unittest2.c
* Description: Unit test for 'getCost' function
* Basic requirements of function getCost():
	1. Getter for the cost of each card
	2. For each card, an integer is returned with the cost of the card
	3. If none of cards are matched in the dominion.c switch statement, 
		an integer -1 is returned.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {

	int cardNumber = 0;
	int returnedValue = 0;

	//begin unit tests
	printf("\n***Unit Tests: getCost()***\n");

	//dominion.c getCost() includes 26 cards
	for (cardNumber = 0; cardNumber < 27; cardNumber++) {

		returnedValue = getCost(cardNumber);

		//Card 0 - Curse - Value: 0
		if (cardNumber == 0) {
			if (returnedValue == 0) {
				printf("\tPassed - Curse card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Curse card returned %d.\n", returnedValue);
			}
		}
		//Card 1 - Estate - Value: 2
		else if (cardNumber == 1) {
			if (returnedValue == 2) {
				printf("\tPassed - Estate card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Estate card returned %d.\n", returnedValue);
			}
		}
		//Card 2 - Duchy - Value: 5
		else if (cardNumber == 2) {
			if (returnedValue == 5) {
				printf("\tPassed - Duchy card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Duchy card returned %d.\n", returnedValue);
			}
		}
		//Card 3 - Province - Value: 8
		else if (cardNumber == 3) {
			if (returnedValue == 8) {
				printf("\tPassed - Province card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Province card returned %d.\n", returnedValue);
			}
		}
		//Card 4 - Copper - Value: 0
		else if (cardNumber == 4) {
			if (returnedValue == 0) {
				printf("\tPassed - Copper card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Copper card returned %d.\n", returnedValue);
			}
		}
		//Card 5 - Silver - Value: 3
		else if (cardNumber == 5) {
			if (returnedValue == 3) {
				printf("\tPassed - Silver card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Silver card returned %d.\n", returnedValue);
			}
		}
		//Card 6 - Gold - Value: 6
		else if (cardNumber == 6) {
			if (returnedValue == 6) {
				printf("\tPassed - Gold card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Gold card returned %d.\n", returnedValue);
			}
		}
		//Card 7 - Adventurer - Value: 6
		else if (cardNumber == 7) {
			if (returnedValue == 6) {
				printf("\tPassed - Adventurer card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Adventurer card returned %d.\n", returnedValue);
			}
		}
		//Card 8 - Council Room - Value: 5
		else if (cardNumber == 8) {
			if (returnedValue == 5) {
				printf("\tPassed - Council Room card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Council Room card returned %d.\n", returnedValue);
			}
		}
		//Card 9 - Feast - Value: 4
		else if (cardNumber == 9) {
			if (returnedValue == 4) {
				printf("\tPassed - Feast card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Feast card returned %d.\n", returnedValue);
			}
		}
		//Card 10 - Gardens - Value: 4
		else if (cardNumber == 10) {
			if (returnedValue == 4) {
				printf("\tPassed - Gardens card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Gardens card returned %d.\n", returnedValue);
			}
		}
		//Card 11 - Mine - Value: 5
		else if (cardNumber == 11) {
			if (returnedValue == 5) {
				printf("\tPassed - Mine card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Mine card returned %d.\n", returnedValue);
			}
		}
		//Card 12 - Remodel - Value: 4
		else if (cardNumber == 12) {
			if (returnedValue == 4) {
				printf("\tPassed - Remodel card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Remodel card returned %d.\n", returnedValue);
			}
		}
		//Card 13 - Smithy - Value: 4
		else if (cardNumber == 13) {
			if (returnedValue == 4) {
				printf("\tPassed - Smithy card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Smithy card returned %d.\n", returnedValue);
			}
		}
		//Card 14 - Village - Value: 3
		else if (cardNumber == 14) {
			if (returnedValue == 3) {
				printf("\tPassed - Village card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Village card returned %d.\n", returnedValue);
			}
		}
		//Card 15 - Baron - Value: 4
		else if (cardNumber == 15) {
			if (returnedValue == 4) {
				printf("\tPassed - Baron card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Baron card returned %d.\n", returnedValue);
			}
		}
		//Card 16 - Great Hall - Value: 3
		else if (cardNumber == 16) {
			if (returnedValue == 3) {
				printf("\tPassed - Great Hall card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Great Hall card returned %d.\n", returnedValue);
			}
		}
		//Card 17 - Minion - Value: 5
		else if (cardNumber == 17) {
			if (returnedValue == 5) {
				printf("\tPassed - Minion card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Minion card returned %d.\n", returnedValue);
			}
		}
		//Card 18 - Steward - Value: 3
		else if (cardNumber == 18) {
			if (returnedValue == 3) {
				printf("\tPassed - Steward card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Steward card returned %d.\n", returnedValue);
			}
		}
		//Card 19 - Tribute - Value: 5
		else if (cardNumber == 19) {
			if (returnedValue == 5) {
				printf("\tPassed - Tribute card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Tribute card returned %d.\n", returnedValue);
			}
		}
		//Card 20 - Ambassador - Value: 3
		else if (cardNumber == 20) {
			if (returnedValue == 3) {
				printf("\tPassed - Ambassador card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Ambassador card returned %d.\n", returnedValue);
			}
		}
		//Card 21 - Cutpurse - Value: 4
		else if (cardNumber == 21) {
			if (returnedValue == 4) {
				printf("\tPassed - Curse card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Curse card returned %d.\n", returnedValue);
			}
		}
		//Card 22 - Embargo - Value: 2
		else if (cardNumber == 22) {
			if (returnedValue == 2) {
				printf("\tPassed - Embargo card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Embargo card returned %d.\n", returnedValue);
			}
		}
		//Card 23 - Outpost - Value: 5
		else if (cardNumber == 23) {
			if (returnedValue == 5) {
				printf("\tPassed - Outpost card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Outpost card returned %d.\n", returnedValue);
			}
		}
		//Card 24 - Salvager - Value: 4
		else if (cardNumber == 24) {
			if (returnedValue == 4) {
				printf("\tPassed - Salvager card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Salvager card returned %d.\n", returnedValue);
			}
		}
		//Card 25 - Sea Hag - Value: 4
		else if (cardNumber == 25) {
			if (returnedValue == 4) {
				printf("\tPassed - Sea Hag card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Sea Hag card returned %d.\n", returnedValue);
			}
		}
		//Card 26 - Treasure Map - Value: 4
		else if (cardNumber == 26) {
			if (returnedValue == 4) {
				printf("\tPassed - Treasure Map card returned %d.\n", returnedValue);
			}
			else {
				printf("\tFailed - Treasure Map card returned %d.\n", returnedValue);
			}
		}

	}

	return 0;
}
