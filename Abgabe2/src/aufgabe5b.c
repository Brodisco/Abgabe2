/*
 * aufgabe5b.c
 *
 *  Created on: 01.11.2022
 *      Author: student
 */
#include <stdio.h>
#include <stdlib.h>
#include "abgabe2.h"

#define coinType 8
#define _FAIL 0
#define _SUCCESS 1

int distributeCoin(int *output, int *coins, int *maxCoins, int endPosition, int input)
{
	int count = 0;
	int ret = _SUCCESS;
	int check = input;
	int revealList[coinType] = {0, 0, 0, 0, 0, 0, 0, 0};

	for (int i = (coinType - 1); i >= endPosition; i--)
	{

		count = 0;

		if (i == coinType - 1 && output[i] == 0)
		{
			int test = (int) input * 0.01;
			test *= 100;

			count = *maxCoins - (input - test);
			if (count == *maxCoins) count = 0;
		}

		if ( ((input / 100) % 2 == 1) && (i == coinType - 7) && output[i] == 0)
		{
			count = 1;
		}

		while ( count < *maxCoins && (input - coins[i] >= 0) && output[i] < *maxCoins)
		{
			input -= coins[i];

			check -= coins[i];

			revealList[i]++;

			output[i]++;

			count++;
		}

	}

	if (check != 0)
	{

		for (int i = 0; i < coinType; i++)
		{
			output[i] -= revealList[i];
		}

		ret = _FAIL;
	}

	return ret;
}

int getUserInput()
{
	float input;
	printf("Input: ");
	scanf("%f", &input);
	printf("\n");
	input *= 100.0001;
	int intInput = (int)input;
	printf("Input Convert:%5d\n", intInput);
	return intInput;
}

void sillyCoinMachine(int input)
{

	int maxCoins = 100;
	int coins[coinType] = {200, 100, 50, 20, 10 , 5 , 2 , 1};
	int output[coinType] = {0, 0, 0, 0, 0, 0, 0, 0};
	int checkSolution = 0;
	int coinCount = 0;

	if (input <= 20000)
	{
		distributeCoin(output, coins, &maxCoins, 0, input);

		for (int i = (coinType - 2); i >= 0; i--)
		{

			if (output[i] > 0)
			{
				int check = _SUCCESS;

				while (check == _SUCCESS)
				{
					check = distributeCoin(output, coins, &maxCoins, (i + 1), coins[i]);

					if (check == _SUCCESS)
					{
						output[i] -= 1;
					}

				}

			}

		}

		for (int i = 0; i < coinType; i++)
		{
			printf("Output: %3.2f: %d \n", (coins[i] / 100.0), output[i]);
			checkSolution += output[i] * coins[i];
			coinCount += output[i];
		}

		if (checkSolution != input)
		{
			printf("End: %d != %d \n", checkSolution, input);
		}

		printf("END with %d Coins! \n", coinCount);

	} else {

		printf("Geldbetrag ist zu Groß! \n");

	}

}
