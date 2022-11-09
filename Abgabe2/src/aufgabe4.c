/*
 * aufgabe4.c
 *
 *  Created on: 09.11.2022
 *      Author: student
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Aufgabe 4
void wurfel(void)
{

	char temp = 0;
	int i = 1;
	srand(time(NULL));
	printf("Für ein Wurf drücken Sie die Eingabetaste. Wenn Sie das Programm beenden möchten, drücken Sie die Taste q.\n");

	while(temp != 'q')
	{
		scanf("%c", &temp);
		if (temp == 'q')
		{
			break;
		}
		else
		printf("%d. Wurf ", i);
		i++;

		char wurfel1 [] [20] = {"Lehm" , "Holz", "Schaf", "Erz", "Getreide", "Gold"};
		char wurfel2 [] [20] = {"Sonne", "Mühle", "Ritter", "Fragezeichen", "Räuber", "Räuber"};

		int r1 = rand() % 6;
		int r2 = rand() % 6;

		printf(" Wurfel 1: %s ", wurfel1[r1]);
		printf(" Wurfel 2: %s", wurfel2[r2]);
	}
}
