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

void smartCoinMachine(int input)
{

	int maxCoins = 100;
	int coins[coinType] = {200, 100, 50, 20, 10, 5, 2, 1};
	int output[coinType] = {0, 0, 0, 0, 0, 0, 0, 0};
	int checkSolution = 0;
	int coinCount = 0;
	int inputBackup = input;

	if (input <= 20000)
	{

		for (int i = 0; i < coinType; i++)
		{

			int count = 0;

			while ( count < maxCoins && (input - coins[i] >= 0) )
			{

				input -= coins[i];

				output[i]++;

				count++;
			}
		}

		for (int i = 0; i < coinType; i++)
		{
			printf("Output: %3.2f: %d \n", (coins[i] / 100.0), output[i]);
			checkSolution += output[i] * coins[i];
			coinCount += output[i];
		}

		if (checkSolution != inputBackup)
		{
			printf("End: %d != %d \n", checkSolution, inputBackup);
		}

		printf("END with %d Coins! \n", coinCount);

	} else {

		printf("Geldbetrag ist zu Groß! \n");

	}

}
