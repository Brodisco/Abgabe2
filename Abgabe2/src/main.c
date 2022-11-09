/*
 * main.c
 *
 *  Created on: 28.10.2022
 *      Author: maximilian
 */

#include <stdio.h>
#include <stdlib.h>


#define coinType 8
#define _FAIL 0
#define _SUCCESS 1

//Aufgabe 1
int min(int* samples, int n);
int max(int* samples, int n);
float mean(int* samples, int n);

//Aufgabe 2
void printIntArray(int* samples, int n);

//Aufgabe 3
int printSumIntArray(int* samples, int n);

//Aufgabe 4
void wurfel(void);

//Aufgabe 5
void nickelback();

int distributeCoin(int *output, int *coins, int *maxCoins, int startPos, int input);
int getUserInput();
void sillyCoinMachine(int input);
int *smartCoinMachine(int input);




int main(void)
{
	//Aufgabe 1
	printf("Aufgabe 1\n");
	int samples[] = { 2, 6, 8, 10, 4 };
	printf("Minimum aus Samples = %d\n", min(samples, 5));
	printf("Maximum aus Samples = %d\n", max(samples, 5));
	printf("Der Mittelwert von Samples = %.2f\n", mean(samples, 5));
	printf("\n\n");

	//Aufgabe 2
	printf("Aufgabe 2\n");
	printIntArray(samples, 5);
	printf("\n\n");

	//Aufgabe 3
	printf("Aufgabe 3\n");
	printf("Summe aus Samples = %d\n", printSumIntArray(samples, 5));
	printf("\n\n");

	//Aufgabe 4
	printf("Aufgabe 4\n");
	wurfel();
	printf("\n\n");

	//Aufgabe 5a/b Mario
	printf("Aufgabe 5a/b Mario\n");
	nickelback();
	printf("\n\n");

	//Aufgabe 5a/b Maxi
	printf("Aufgabe 5a/b Maxi\n");
	smartCoinMachine(getUserInput());
	sillyCoinMachine(getUserInput());

	return EXIT_SUCCESS;
}
