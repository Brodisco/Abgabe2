/*
 * aufgabe3.c
 *
 *  Created on: 09.11.2022
 *      Author: student
 */

#include <stdio.h>
#include <stdlib.h>

//Aufgabe 3
int printSumIntArray(int* samples, int n)
{
	int summe = 0;
	for (int i = 0; i < n; i++) {
		summe += samples[i];
	}

	return summe;
}
