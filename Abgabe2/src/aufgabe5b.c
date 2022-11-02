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

int distributeCoin(int *output, int *coins, int *maxCoins, int *intInput)
{
	int count = 0;

	int ret = 0;

	for (int i = (coinType - 1); i >= 0; i--)
	{

		printf("intInput: %5d ", *intInput);

		count = 0;

		if (i == coinType - 1)
		{
			int test = (int) *intInput * 0.01;
			test *= 100;

			count = *maxCoins - (*intInput - test);
			if (count == *maxCoins) count = 0;
		}

		if ( ((*intInput / 100) % 2 == 1) && (i == coinType - 7) )
		{
			count = 1;
		}

		while ( count < *maxCoins && (*intInput - coins[i] >= 0) )
		{
			*intInput -= coins[i];

			output[i]++;

			count++;
		}

		printf("- %d \n", output[i] * coins[i]);

	}
	printf("\n");
}

void sillyCoinMachine()
{


	int maxCoins = 100;
	static int coins[coinType] = {200, 100, 50, 20, 10 , 5 , 2 , 1};
	static int output[coinType] = {0, 0, 0, 0, 0, 0, 0, 0};
	static int coinCount[coinType] = {0, 0, 0, 0, 0, 0, 0, 0};

	float input;
	printf("Input: ");
	scanf("%f", &input);
	printf("\n");
	input *= 100;
	int intInput = (int)input;




	if (input <= 20000)
	{
		distributeCoin(output, coins, &maxCoins, &intInput);

		for (int i = 0; i < coinType; i++)
		{
			printf("Output: %3d: %d \n", coins[i], output[i]);
		}

		for (int i = (coinType - 2); i >= 0; i--)
		{
			if (output[i] > 0)
			{
				printf("Check Coin %d \n", coins[i]);
			}

		}


	} else {

		printf("Geldbetrag ist zu Groß! \n");

	}



}
