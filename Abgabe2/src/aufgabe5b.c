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

int distributeCoin(int *output, int *coins, int *maxCoins, int startPos, int input)
{
	int count = 0;
	int ret = _SUCCESS;
	int check = input;
	int revealList[coinType] = {0, 0, 0, 0, 0, 0, 0, 0};

	for (int i = startPos; i < coinType; i++)
	{

		count = 0;

		while ( count < maxCoins[i] && (input - coins[i] >= 0) && output[i] < maxCoins[i])
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

	int maxCoin[coinType] = {100, 100, 100, 100, 100, 100, 100, 1};
	int coins[coinType] = {200, 100, 50, 20, 10 , 5 , 2 , 1};
	int *output;
	int checkSolution = 0;
	int coinCount = 0;

	if (input <= 20000)
	{

		output = smartCoinMachine(input);



		for (int i = 0; i < coinType; i++)
		{

			if (output[i] > 0)
			{
				int check = _SUCCESS;
				int mulitplikator = 1;



				while (check == _SUCCESS)
				{

					check = distributeCoin(output, coins, maxCoin, (i + 1), coins[i] * mulitplikator);


					if (check == _SUCCESS)
					{

						output[i] -= mulitplikator;

					} else {

						if (output[i] > 0 && i == 5)
						{
							if (mulitplikator == 2)
							{
								if (output[7] == 1 && (output[6] <= maxCoin[6] - 3 ) )
								{
									output[7] = 0;
									distributeCoin(output, coins, maxCoin, (i + 1), coins[i] + 1);
									output[i] -= 1;
								}

								break;
							}
							mulitplikator = 2;

							if (mulitplikator <= 2)
							{
								check = _SUCCESS;
							} else {
								break;
							}

						}
					}

					if (output[i] == 0)
					{
						check = _FAIL;
					}
					/*
					for (int i = 0; i < coinType; i++)
					{
						printf("Output: %3.2f: %d \n", (coins[i] / 100.0), output[i]);
					}
					*/
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
			printf("SILLY MACHINE ERROR: %d != %d \n", checkSolution, input);
		}

		printf("SILLY MACHINE ENDS with %d Coins! \nCheckVal: %d\n", coinCount, checkSolution);

	} else {

		printf("Geldbetrag ist zu Groß! \n");

	}
}
