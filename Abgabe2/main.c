/*
 * main.c
 *
 *  Created on: 28.10.2022
 *      Author: maximilian
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int min(int* samples, int n) {
	// Rückgabe des Minimums
	int min = samples[0];
	for (int i = 1; i < n; i++) {
		if (samples[i] < min) {
			min = samples[i];
		}
	}
	return min;
}

int max(int* samples, int n) {
	// Rückgabe des Minimums
	int max = samples[0];
	for (int i = 1; i < n; i++) {
		if (samples[i] > max) {
			max = samples[i];
		}
	}
	return max;
}

float mean(int* samples, int n) {
	// Rückgabe des Minimums
	float mittelwert = 0;
	for (int i = 0; i < n; i++) {
		mittelwert += samples[i];
	}
	mittelwert = mittelwert / n;
	return mittelwert;
}

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

int printSumIntArray(int* samples, int n)
{
	int summe = 0;
	for (int i = 0; i < n; i++) {
		summe += samples[i];
	}

	return summe;
}

void rollTheDices() {
	srand(time(NULL));
	char input;
	int anzahlWuerfe = 1;

	const char *wuerfel1[6];
	wuerfel1[0] = "Lehm";
	wuerfel1[1] = "Holz";
	wuerfel1[2] = "Schaf";
	wuerfel1[3] = "Erz ";
	wuerfel1[4] = "Getreide";
	wuerfel1[5] = "Gold";

	const char *wuerfel2[6];
	wuerfel2[0] = "Sonne";
	wuerfel2[1] = "Mühle";
	wuerfel2[2] = "Ritter";
	wuerfel2[3] = "Fragezeichen";
	wuerfel2[4] = "Räuber";
	wuerfel2[5] = "Räuber";

	printf("Die Eingabetaste druecken um zu würfeln. Mit q kann das Spiel beendet werden. \n");

	while (input != 'q') {
		printf("%i. Wurf: \t Würfel 1: %s \t Würfel 2: %s", anzahlWuerfe, wuerfel1[rand()%6], wuerfel2[rand()%6]);
		scanf("%c", &input);
		anzahlWuerfe++;
	}
}

int main(void)
{
	printf("Abgabe 2\n");
	printf("\nAufgabe 1\n");

	//Aufgabe 1
	int samples[] = { 2, 6, 8, 10, 4};
	printf("Minimum aus Samples = %d\n", min(samples, 5));
	printf("Maximum aus Samples = %d\n", max(samples, 5));
	printf("Der Mittelwert von Samples = %f\n", mean(samples, 5));

	// Aufgabe 2
	printf("\nAufgabe 2\n");
	printIntArray(samples, 5);

	// Aufgabe 3
	printf("\nAufgabe 3\n");
	int summe = printSumIntArray(samples, 5);
	printf("Die Summe ist: = %d\n", summe);

	// Aufgabe 4
	printf("\nAufgabe 4\n");
	rollTheDices();

	// Aufgabe 5
	printf("\nAufgabe 5\n");

	return EXIT_SUCCESS;
}
