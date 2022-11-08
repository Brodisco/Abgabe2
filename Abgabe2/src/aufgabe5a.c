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

	int maxCoin[coinType] = {100, 100, 100, 100, 100, 100, 100, 1};
	int coins[coinType] = {200, 100, 50, 20, 10, 5, 2, 1};

	static int output[coinType];
	for (int i = 0; i < coinType; i++)
	{
		output[i] = 0;
	}

	int checkSolution = 0;
	int coinCount = 0;
	int inputBackup = input;

	if (input <= 20000)
	{

		for (int i = 0; i < coinType; i++)
		{

			int count = 0;

			while ( count < maxCoin[i] && (input - coins[i] >= 0) )
			{

				input -= coins[i];

				output[i]++;

				count++;
			}
		}

		for (int i = 0; i < coinType; i++)
		{
			//printf("Output: %3.2f: %d \n", (coins[i] / 100.0), output[i]);
			checkSolution += output[i] * coins[i];
			coinCount += output[i];
		}

		if (checkSolution != inputBackup)
		{
			printf("Error End: %d != %d \n", checkSolution, inputBackup);
		}

		//printf("SMART MACHINE END with %d Coins! \n", coinCount);

	} else {

		printf("Geldbetrag ist zu Groß! \n");

	}
	return output;
}
