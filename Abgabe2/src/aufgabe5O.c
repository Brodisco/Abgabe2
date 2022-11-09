/*
 * aufgabe5O.c
 *
 *  Created on: 09.11.2022
 *      Author: student
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define coinType 8
#define _FAIL 0
#define _SUCCESS 1

int getUserInput()
{
	float input;

	printf("Input: ");
	scanf("%f", &input);
	printf("\n");

	// to make sure that the input is not round up to a lower value
	input *= 100.0001;
	int intInput = (int)input;
	printf("Input Convert:%5d\n", intInput);
	return intInput;
}

//Aufgabe 5a/b Maxi
int distributeCoin(int *output, int *coins, int *maxCoins, int startPos, int input)
{
	//int count = 0;
	//int check = input;

	//return value of this function
	int ret = _SUCCESS;

	// lokal array which stores the changes on the outputarray to undo these if the changes are not leagel
	int revealList[coinType] = {0, 0, 0, 0, 0, 0, 0, 0};

	// loop starts at a specific coin
	for (int i = startPos; i < coinType; i++)
	{

		//count = 0;

		// loop's as long as the amount of coins of each type is lower than the max coin amount
		// loop's as long as it is possible to subtract a nother coin form the input value
		// loop's as long the specific outputcoin amount is lower than the max coin amount
		//while ( count < maxCoins[i] && (input - coins[i] >= 0) && output[i] < maxCoins[i])
		while ( (input - coins[i] >= 0) && output[i] < maxCoins[i])
		{
			input -= coins[i];

			//check -= coins[i];

			revealList[i]++;

			output[i]++;

			//count++;
		}

	}

	// if the for loop was not successful to distribute the coin to smaller value of coins all changes are reversed
	//if (check != 0)
	if (input != 0)
	{

		for (int i = 0; i < coinType; i++)
		{
			output[i] -= revealList[i];
		}

		// Set the return value to false
		ret = _FAIL;
	}

	return ret;
}

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

void sillyCoinMachine(int input)
{

	int maxCoin[coinType] = {100, 100, 100, 100, 100, 100, 100, 1};
	int coins[coinType] = {200, 100, 50, 20, 10 , 5 , 2 , 1};

	// Pointer which will point to the outputarray of the previous function
	int *output = NULL;
	int checkSolution = 0;
	int coinCount = 0;

	if (input <= 20000)
	{

		// The smartCoinMachine retuns the adress of his output array
		output = smartCoinMachine(input);


		// The following code is responsible to take every coin from the top and try to distribute it to some lower coinvalues
		for (int i = 0; i < coinType; i++)
		{

			// check if the coin is part of the output or not
			if (output[i] > 0)
			{

				int check = _SUCCESS;

				// if mulitplikator is zero distributing 5 to 2 is not possible
				// if mulitplikator is two distributing 5 * 2 to 2 is possible
				int mulitplikator = 1;

				// loops as long as it is possible to distribute a single coins to more lower coins
				while (check == _SUCCESS)
				{
					// function which distributes the coins
					check = distributeCoin(output, coins, maxCoin, (i + 1), coins[i] * mulitplikator);

					// if it was successfull to distribute a coin the distributed coin is subtracted from the output array
					if (check == _SUCCESS)
					{

						output[i] -= mulitplikator;

					} else {

						// in the end there could be some problems to distribute a 5 to 2 and 1 s
						if (output[i] > 0 && i == 5)
						{

							if (mulitplikator == 2)
							{
								// this part is responsible if the the case occurs that distributing a 5 is not possible because there is a single 1 coin left
								if (output[7] == 1 && (output[6] <= maxCoin[6] - 3 ) )
								{
									output[7] = 0;
									distributeCoin(output, coins, maxCoin, (i + 1), coins[i] + 1);
									output[i] -= 1;
								}

								break;
							}

							mulitplikator = 2;

							check = _SUCCESS;

						}
					}

					if (output[i] == 0)
					{
						check = _FAIL;
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
			printf("SILLY MACHINE ERROR: %d != %d \n", checkSolution, input);
		}

		printf("SILLY MACHINE ENDS with %d Coins! \nCheckVal: %d\n", coinCount, checkSolution);

	} else {

		printf("Coinamount to large! \n");

	}
}
