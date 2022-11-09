/*
 * main.c
 *
 *  Created on: 28.10.2022
 *      Author: maximilian
 */

#include <stdio.h>
#include <stdlib.h>
#include "abgabe2.h"


int main(void)
{


	printf("Abgabe 2\n");

	int samples[] = { 2, 4, 6, 8, 10, 4, 1, 2};

	printf("Minimum des Samples: %d \n", min(samples, 8));
	printf("Maximum des Samples: %d \n", max(samples, 8));
	printf("Maximum des Samples: %f \n", mean(samples, 8));

	printIntArray(samples, 8);

	printf("Summe des Samples: %d \n", printSumIntArray(samples, 8));

	profBWurfel();

	smartCoinMachine(getUserInput());



/*
	for (int i = 0; i <= 20000; i++)
	{
		sillyCoinMachine(i);
	}
	printf("Test Successfull \n");
*/


	sillyCoinMachine(getUserInput());

	return EXIT_SUCCESS;
}
