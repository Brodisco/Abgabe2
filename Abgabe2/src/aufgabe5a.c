/*
 * aufgabe5a.c
 *
 *  Created on: 01.11.2022
 *      Author: student
 */
#include <stdio.h>
#include <stdlib.h>
#include "abgabe2.h"

int *smartCoinMachine()
{
	#define coinType 8

	int maxCoins = 100;
	double coins[coinType] = {2.0, 1.0, 0.5, 0.2, 0.1 , 0.05 , 0.02 , 0.01};
	static int output[coinType] = {0, 0, 0, 0, 0, 0, 0, 0};

	float input;
	printf("Input: ");
	scanf("%f", &input);



	if (input <= 200)
	{

		for (int i = 0; i < coinType; i++)
		{

			//printf("Stöbere in %f Euro \n", coins[i]);

			int count = 0;

			while ( count < maxCoins && (input - coins[i] >= -0.001) )
			{
				//printf("%d: %f - %f ", count, input, coins[i]);

				input -= coins[i];

				//printf("= %f \n", input);

				output[i]++;

				count++;
			}
		}

		//printf("End: %f \n", input);

		for (int i = 0; i < coinType; i++)
		{
			printf("Coin %1.2f: %d \n", coins[i], output[i]);
		}


	} else {

		printf("Geldbetrag ist zu Groß! \n");

	}

	return output;
}
