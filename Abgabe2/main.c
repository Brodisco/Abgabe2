#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int min(int* samples, int n){
	int result = 0;
	for (int i = 0; i < n; ++i) {
		if (result > *(samples + i)) { //position im Array
			result = *(samples + i);
		}
	}
	return result;
}

int max(int* samples, int n){
	int result = 0;

	for (int i = 0; i < n; ++i) {
		if (result < *(samples + i)) { //position im Array
			result = *(samples + i);
		}
	}
	return result;

}

float mean(int* samples, int n){
	float result = 0.0f; 
	for (int i = 0; i < n; ++i) {
		result += *(samples + i);//direkter zugriff auf die Adresse weil er int nicht in float umwandeln will :(
	}
	return result;
}

void printIntArray(int* samples, int n){
	for (int i = n; i >=0; --i) {
		printf("number: %i\n", samples[i]);	
	}
}
int sumIntArray(int* samples, int n){
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += samples[i];
	}
	printf("summe: %i\n",sum);
	return sum;
}

void siedlerWuerfel(){
	srand(time(NULL));
	int antwort;
	int Wurf1 = rand() % 6;
	int Wurf2 = rand() % 6;
	char* wuerfel1[] = {"Lehm", "Holz", "Schaf", "Erz", "Getreide", "Gold" };
	char* wuerfel2[] = {"Sonne", "Muehle", "Ritter", "Fragezeichen", "Raeuber", "Raeuber"};
	printf("erster Wuerfel: %s\n", wuerfel1[Wurf1]);
	printf("zweiter Wuerfel: %s\n", wuerfel2[Wurf2]);
	printf("weiterer wurf?: ");
	scanf("%1i", &antwort);

	if (antwort == 1) {
		siedlerWuerfel();
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
		scanf("%6f", &eingabe);
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


int main()
{
	
	return 0;
}
