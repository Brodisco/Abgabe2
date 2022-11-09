/*
 * aufgabe5M.c
 *
 *  Created on: 09.11.2022
 *      Author: student
 */

#include <stdio.h>
#include <stdlib.h>

//Aufgabe 5 a/b Mario
void nickelback()
{
	// Aufgabe a
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

	int eingabe_cent = eingabe * 100.0001;

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
	printf("Gesamtanzahl Münzen: %i \t Betrag in Cent: %i \n", muenze_e2 + muenze_e1 + muenze_c50 + muenze_c20 + muenze_c10 + muenze_c5 + muenze_c2 + muenze_c1, muenze_e2*200 + muenze_e1*100 + muenze_c50*50 + muenze_c20*20 + muenze_c10*10 + muenze_c5*5 + muenze_c2*2 + muenze_c1*1);



	// Aufgabe b

	muenze_e2 = 0;
	muenze_e1 = 0;
	muenze_c50 = 0;
	muenze_c20 = 0;
	muenze_c10 = 0;
	muenze_c5 = 0;
	muenze_c2 = 0;
	muenze_c1 = 0;

	eingabe_cent = eingabe * 100.0001;

	/*
	MaxB.	Summe
	200.00  38701
	100.00  18701
	50.00    8701
	20.00    3701
	10.00    1701
	5.00      701
	2.00      201
	0.01        1
	*/


	if (eingabe_cent > 1 && eingabe_cent <= 201) {
		// Mit 2 Cent Stücken lösbar
		while (eingabe_cent > 1 && muenze_c2 < 100) {
			muenze_c2++;
			eingabe_cent -= 2;
		}
	} else if (eingabe_cent > 201 && eingabe_cent <= 701) {
		// Mit 5 Cent und 2 Cent lösbar
		// So lange mit 5 Cent auffüllen bis mit 2 Cent lösbar
		while (eingabe_cent > 201 && muenze_c5 < 100) {
			muenze_c5++;
			eingabe_cent -= 5;
		}
		// Rest mit 2 Cent auffüllen
		while (eingabe_cent > 1 && muenze_c2 < 100) {
			muenze_c2++;
			eingabe_cent -= 2;
		}
	} else if (eingabe_cent > 701 && eingabe_cent <= 1701) {
		// Mit 10 Cent, 5 Cent und 2 Cent lösbar
		// So lange mit 10 Cent auffüllen bis mit 5 Cent lösbar
		while (eingabe_cent > 701 && muenze_c10 < 100) {
			muenze_c10++;
			eingabe_cent -= 10;
		}
		// So lange mit 5 Cent auffüllen bis mit 2 Cent lösbar
		while (eingabe_cent > 201 && muenze_c5 < 100) {
			muenze_c5++;
			eingabe_cent -= 5;
		}
		// Rest mit 2 Cent auffüllen
		while (eingabe_cent > 1 && muenze_c2 < 100) {
			muenze_c2++;
			eingabe_cent -= 2;
		}
	} else if (eingabe_cent > 1701 && eingabe_cent <= 3701) {
		// Mit 20 Cent, 10 Cent, 5 Cent und 2 Cent lösbar
		// So lange mit 20 Cent auffüllen bis mit 10 Cent lösbar
		while (eingabe_cent > 1701 && muenze_c20 < 100) {
			muenze_c20++;
			eingabe_cent -= 20;
		}
		// So lange mit 10 Cent auffüllen bis mit 5 Cent lösbar
		while (eingabe_cent > 701 && muenze_c10 < 100) {
			muenze_c10++;
			eingabe_cent -= 10;
		}
		// So lange mit 5 Cent auffüllen bis mit 2 Cent lösbar
		while (eingabe_cent > 201 && muenze_c5 < 100) {
			muenze_c5++;
			eingabe_cent -= 5;
		}
		// Rest mit 2 Cent auffüllen
		while (eingabe_cent > 1 && muenze_c2 < 100) {
			muenze_c2++;
			eingabe_cent -= 2;
		}
	} else if (eingabe_cent > 3701 && eingabe_cent <= 8701) {
		// Mit 50 Cent, 20 Cent, 10 Cent, 5 Cent und 2 Cent lösbar
		// So lange mit 50 Cent auffüllen bis mit 20 Cent lösbar
		while (eingabe_cent > 3701 && muenze_c50 < 100) {
			muenze_c50++;
			eingabe_cent -= 50;
		}
		// So lange mit 20 Cent auffüllen bis mit 10 Cent lösbar
		while (eingabe_cent > 1701 && muenze_c20 < 100) {
			muenze_c20++;
			eingabe_cent -= 20;
		}
		// So lange mit 10 Cent auffüllen bis mit 5 Cent lösbar
		while (eingabe_cent > 701 && muenze_c10 < 100) {
			muenze_c10++;
			eingabe_cent -= 10;
		}
		// So lange mit 5 Cent auffüllen bis mit 2 Cent lösbar
		while (eingabe_cent > 201 && muenze_c5 < 100) {
			muenze_c5++;
			eingabe_cent -= 5;
		}
		// Rest mit 2 Cent auffüllen
		while (eingabe_cent > 1 && muenze_c2 < 100) {
			muenze_c2++;
			eingabe_cent -= 2;
		}
	} else if (eingabe_cent > 8701 && eingabe_cent <= 18701) {
		// Mit 1€, 50 Cent, 20 Cent, 10 Cent, 5 Cent und 2 Cent lösbar
		// So lange mit 1€ auffüllen bis mit 50 Cent lösbar
		while (eingabe_cent > 8701 && muenze_e1 < 100) {
			muenze_e1++;
			eingabe_cent -= 100;
		}
		// So lange mit 50 Cent auffüllen bis mit 20 Cent lösbar
		while (eingabe_cent > 3701 && muenze_c50 < 100) {
			muenze_c50++;
			eingabe_cent -= 50;
		}
		// So lange mit 20 Cent auffüllen bis mit 10 Cent lösbar
		while (eingabe_cent > 1701 && muenze_c20 < 100) {
			muenze_c20++;
			eingabe_cent -= 20;
		}
		// So lange mit 10 Cent auffüllen bis mit 5 Cent lösbar
		while (eingabe_cent > 701 && muenze_c10 < 100) {
			muenze_c10++;
			eingabe_cent -= 10;
		}
		// So lange mit 5 Cent auffüllen bis mit 2 Cent lösbar
		while (eingabe_cent > 201 && muenze_c5 < 100) {
			muenze_c5++;
			eingabe_cent -= 5;
		}
		// Rest mit 2 Cent auffüllen
		while (eingabe_cent > 1 && muenze_c2 < 100) {
			muenze_c2++;
			eingabe_cent -= 2;
		}
	} else if (eingabe_cent > 18701 && eingabe_cent <= 20000) {
		// Nur mit allen Münzen lösbar.
		// So lange mit 2€ auffüllen bis mit 1€ lösbar
		while (eingabe_cent > 18701 && muenze_e2 < 100) {
			muenze_e2++;
			eingabe_cent -= 200;
		}
		// So lange mit 1€ auffüllen bis mit 50 Cent lösbar
		while (eingabe_cent > 8701 && muenze_e1 < 100) {
			muenze_e1++;
			eingabe_cent -= 100;
		}
		// So lange mit 50 Cent auffüllen bis mit 20 Cent lösbar
		while (eingabe_cent > 3701 && muenze_c50 < 100) {
			muenze_c50++;
			eingabe_cent -= 50;
		}
		// So lange mit 20 Cent auffüllen bis mit 10 Cent lösbar
		while (eingabe_cent > 1701 && muenze_c20 < 100) {
			muenze_c20++;
			eingabe_cent -= 20;
		}
		// So lange mit 10 Cent auffüllen bis mit 5 Cent lösbar
		while (eingabe_cent > 701 && muenze_c10 < 100) {
			muenze_c10++;
			eingabe_cent -= 10;
		}
		// So lange mit 5 Cent auffüllen bis mit 2 Cent lösbar
		while (eingabe_cent > 201 && muenze_c5 < 100) {
			muenze_c5++;
			eingabe_cent -= 5;
		}
		// Rest mit 2 Cent auffüllen
		while (eingabe_cent > 1 && muenze_c2 < 100) {
			muenze_c2++;
			eingabe_cent -= 2;
		}
	}

	// Auf ungerade Zahl prüfen
		if (eingabe_cent % 2 != 0) {
			muenze_c1++;
			eingabe_cent -= 1;
		}

	printf("Kleine Münzen: ");
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
		printf("Gesamtanzahl Münzen: %i \t Betrag in Cent: %i \n", muenze_e2 + muenze_e1 + muenze_c50 + muenze_c20 + muenze_c10 + muenze_c5 + muenze_c2 + muenze_c1, muenze_e2*200 + muenze_e1*100 + muenze_c50*50 + muenze_c20*20 + muenze_c10*10 + muenze_c5*5 + muenze_c2*2 + muenze_c1*1);
}
