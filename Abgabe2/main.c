/*
 * main.c
 *
 *  Created on: 28.10.2022
 *      Author: maximilian
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


/*
 *  Aufgabe 3
 */

int printSumIntArray(int *samples, int n)
{
	int result = 0;

	for (int i = 0; i < n; i++)
	{
		result += *(samples + i);
	}

	return result;
}

/*
 * Aufgabe 1
 */
int min(int *samples, int n)
{
	int result;

	for (int i = 0; i < n; i++)
	{
		if (result > *(samples + i))
		{
			result = *(samples + i);
		}
	}

	return result;
}

int max(int *samples, int n)
{
	int result;

	for (int i = 0; i < n; i++)
	{
		if (result < *(samples + i))
		{
			result = *(samples + i);
		}
	}

	return result;
}

float mean(int *samples, int n)
{
	float result = printSumIntArray(samples, n);

	return (result / n);
}

/*
 * Aufgabe 2
 */

void printIntArray(int *samples, int n)
{
	printf("samples[] = {");
	for (int i = (n - 1); i >= 0; i--)
	{
		printf(" %d,", *(samples + i));
	}
	printf("}\n");
}

/*
 *  Aufgabe 4
 */

void profBWurfel()
{
	char wurfel1[6][20] = {"Lehm", "Holz", "Schaf", "Erz", "Getreide", "Gold"};
	char wurfel2[6][20] = {"Sonne", "Mühle", "Ritter", "Fragezeichen", "Rauber", "Rauber" };

	srand(time(NULL));

	printf("Würfel1: %s \n", wurfel1[rand() % 6]);
	printf("Würfel2: %s \n", wurfel2[rand() % 6]);
}

/*
 *  Aufgabe 5
 */

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



void sillyCoinMachine()
{
	#define coinType 8

	int maxCoins = 100;
	int coins[coinType] = {200, 100, 50, 20, 10 , 5 , 2 , 1};
	int output[coinType] = {0, 0, 0, 0, 0, 0, 0, 0};

	float input;
	printf("Input: ");
	scanf("%f", &input);
	input *= 100;
	int intInput = (int)input;

	int count = 0;

	printf("\n");

	if (input <= 20000)
	{
		for (int i = (coinType - 1); i >= 0; i--)
		{

			printf("intInput: %5d ", intInput);

			count = 0;

			if (i == coinType - 1)
			{
				int test = (int) intInput * 0.01;
				test *= 100;

				count = maxCoins - (intInput - test);
				if (count == maxCoins) count = 0;
			}

			if ( ((intInput / 100) % 2 == 1) && (i == coinType - 7) )
			{
				count = 1;
			}

			while ( count < maxCoins && (intInput - coins[i] >= 0) )
			{

				intInput -= coins[i];

				output[i]++;

				count++;

			}
			printf("- %d \n", output[i] * coins[i]);

		}

		printf("\nEnd: %d \n \n", intInput);

		for (int i = 0; i < coinType; i++)
		{
			printf("Coin %3d: %d \n", coins[i], output[i]);
		}



	} else {

		printf("Geldbetrag ist zu Groß! \n");

	}

	printf("\n");


	int rebase = maxCoins - output[coinType - 1];

	printf("Rebase: %d \n", rebase);

	rebase /= 2;



	output[coinType - 1] += (rebase * 2);
	output[coinType - 2] -= rebase;


	for (int i = 0; i < coinType; i++)
	{
		printf("Coin %3d: %d \n", coins[i], output[i]);
	}

}


int main(void)
{
	/*

	printf("Abgabe 2\n");

	int samples[] = { 2, 4, 6, 8, 10, 4, 0, -3};

	printf("Minimum des Samples: %d \n", min(samples, 8));
	printf("Maximum des Samples: %d \n", max(samples, 8));
	printf("Maximum des Samples: %f \n", mean(samples, 8));

	printIntArray(samples, 8);

	printf("Summe des Samples: %d \n", printSumIntArray(samples, 8));

	profBWurfel();
	*/
	//smartCoinMachine();


	sillyCoinMachine();



	return EXIT_SUCCESS;
}
