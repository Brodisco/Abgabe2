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

void nickelback() {
	int muenze_e2 = 0;
	int muenze_e1 = 0;
	int muenze_c50 = 0;
	int muenze_c20 = 0;
	int muenze_c10 = 0;
	int muenze_c5 = 0;
	int muenze_c2 = 0;
	int muenze_c1 = 0;
	float eingabe = 0.00;

	printf("Bitte geben Sie einen Betrag bis 200€ mit maximal zwei Nachkommastellen ein. \n");
	while (eingabe <= 0.00 || eingabe > 200.00) {
		printf("Ihre Eingabe: ");
		scanf("%f", &eingabe);
		if (eingabe <= 0.00 || eingabe > 200.00) {
			printf("Kein korrekter Betrag eingegeben. Bitte noch einmal wiederhohlen. \n");
		}
	}


	int eingabe_cent = eingabe * 100;
	// printf("%i", eingabe_cent);

	while (eingabe_cent > 0) {
		if (eingabe_cent >= 200 && muenze_e2 < 100) {
			// 2€ Stück verwenden
			muenze_e2++;
			eingabe_cent -= 200;
		} else if (eingabe_cent >= 100 && muenze_e1 < 100) {
			// 1€ Stück verwenden
			muenze_e1++;
			eingabe_cent -= 100;
		} else if (eingabe_cent >= 50 && muenze_c50 < 100) {
			// 50Cent Stück verwenden
			muenze_c50++;
			eingabe_cent -= 50;
		} else if (eingabe_cent >= 20 && muenze_c20 < 100) {
			// 20Cent Stück verwenden
			muenze_c20++;
			eingabe_cent -= 20;
		} else if (eingabe_cent >= 10 && muenze_c10 < 100) {
			// 10Cent Stück verwenden
			muenze_c10++;
			eingabe_cent -= 10;
		} else if (eingabe_cent >= 5 && muenze_c5 < 100) {
			// 5Cent Stück verwenden
			muenze_c5++;
			eingabe_cent -= 5;
		} else if (eingabe_cent >= 2 && muenze_c2 < 100) {
			// 2Cent Stück verwenden
			muenze_c2++;
			eingabe_cent -= 2;
		} else if (eingabe_cent >= 1 && muenze_c1 < 1) {
			// 1Cent Stück verwenden
			muenze_c1++;
			eingabe_cent -= 1;
		}
	}
	printf("Große Münzen: ");
	if (muenze_e2 > 0) {
		printf("%i x 2 Euro, ", muenze_e2);
	}
	if (muenze_e1 > 0) {
		printf("%i x 1 Euro, ", muenze_e1);
	}
	if (muenze_c50 > 0) {
		printf("%i x 50 Cent, ", muenze_c50);
	}
	if (muenze_c20 > 0) {
		printf("%i x 20 Cent, ", muenze_c20);
	}
	if (muenze_c10 > 0) {
		printf("%i x 10 Cent, ", muenze_c10);
	}
	if (muenze_c5 > 0) {
		printf("%i x 5 Cent, ", muenze_c5);
	}
	if (muenze_c2 > 0) {
		printf("%i x 2 Cent, ", muenze_c2);
	}
	if (muenze_c1 > 0) {
		printf("%i x 1 Cent, ", muenze_c1);
	}
	printf("\n");
}

int main(void)
{
	/*
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
*/
	// Aufgabe 5
	printf("\nAufgabe 5\n");
	nickelback();

	return EXIT_SUCCESS;
}
