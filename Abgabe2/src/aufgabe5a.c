/*
 * aufgabe5a.c
 *
 *  Created on: 01.11.2022
 *      Author: student
 */
#include <stdio.h>
#include <stdlib.h>
#include "abgabe2.h"
#define coinType 8

int *smartCoinMachine(int input)
{
	// max amount of each coin
	int maxCoin[coinType] = {100, 100, 100, 100, 100, 100, 100, 1};

	// Value of each coin
	int coins[coinType] = {200, 100, 50, 20, 10, 5, 2, 1};

	// declarea a static array
	// if this function called a second time the value of this array is set to zero
	static int output[coinType];
	for (int i = 0; i < coinType; i++)
	{
		output[i] = 0;
	}

	// lokal variable which checks the endresult
	int checkSolution = 0;

	// Variable which stores the total amount of the released coins
	int coinCount = 0;

	// Variable stores the value of the input because input is affected during the process
	int inputBackup = input;

	if (input <= 20000)
	{

		// iterate throw all types of coins
		for (int i = 0; i < coinType; i++)
		{

			int count = 0;

			// loop's as long as the amount of coins of each type is lower than the max coin amount
			// loop's as long as it is possible to subtract a nother coin form the input value
			while ( count < maxCoin[i] && (input - coins[i] >= 0) )
			{

				input -= coins[i];

				output[i]++;

				count++;
			}
		}

		//Checks the correctness of the output
		for (int i = 0; i < coinType; i++)
		{
			printf("Output: %3.2f: %d \n", (coins[i] / 100.0), output[i]);
			checkSolution += output[i] * coins[i];
			coinCount += output[i];
		}

		// Output is incorrect
		if (checkSolution != inputBackup)
		{
			printf("Error End: %d != %d \n", checkSolution, inputBackup);
		}

		printf("SMART MACHINE END with %d Coins! \n", coinCount);

	} else {

		printf("Coinamount is to large \n");

	}

	// returns the address of the static output array to a second function
	return output;
}
