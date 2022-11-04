/*
 * main.c
 *
 *  Created on: 28.10.2022
 *      Author: maximilian
 */

#include <stdio.h>
#include <stdlib.h>

int min(int* samples, int n) {
	// Rückgabe des Minimums
}

int max(int* samples, int n) {
	// Rückgabe des Minimums

}

float mean(int* samples, int n) {
	// Rückgabe des Minimums

}

int main(void)
{
//Aufgabe 1
int samples[] = { 2, 6, 8, 10, 4 };
printf("Minimum aus Samples = %d\n", min(samples, 5));
printf("Maximum aus Samples = %d\n", max(samples, 5));
printf("Der Mittelwert von Samples = %f\n", mean(samples, 5));
return 0;
}

int main(void)
{
	printf("Abgabe 2\n");
	printf("Aufgabe 1\n");

	//Aufgabe 1
	int samples[] = { 2, 6, 8, 10, 4 };
	printf("Minimum aus Samples = %d\n", min(samples, 5));
	printf("Maximum aus Samples = %d\n", max(samples, 5));
	printf("Der Mittelwert von Samples = %f\n", mean(samples, 5));

	return EXIT_SUCCESS;
}
