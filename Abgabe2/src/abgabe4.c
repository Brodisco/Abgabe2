/*
 * abgabe4.c
 *
 *  Created on: 01.11.2022
 *      Author: student
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abgabe2.h"

void profBWurfel()
{

	char wurfel1[6][20] = {"Lehm", "Holz", "Schaf", "Erz", "Getreide", "Gold"};
	char wurfel2[6][20] = {"Sonne", "Mühle", "Ritter", "Fragezeichen", "Rauber", "Rauber" };

	srand(time(NULL));

	char c = '\0';

	while(c != 'q')
	{
		printf("ENTER für neuen Versuch : q für Quit:");
		scanf("%c", &c);
		printf("\n");

		if (c == 'q') break;

		printf("Würfel1: %s \n", wurfel1[rand() % 6]);
		printf("Würfel2: %s \n", wurfel2[rand() % 6]);
	}

}
