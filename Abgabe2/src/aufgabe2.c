/*
 * aufgabe2.c
 *
 *  Created on: 09.11.2022
 *      Author: student
 */

#include <stdio.h>
#include <stdlib.h>


//Aufgabe 2
void printIntArray(int* samples, int n)
{
	printf("samples[] = { ");
	for (int i = 1; i < n; i++) {
		printf("%i, ", samples[n-i]);
	}
	// Letzte Zahl ohne Komma drucken
	printf("%i ", samples[0]);
	printf("} \n");
}
