//Übungsblatt 2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Aufgabe 1
//a)
int min(int* samples, int n)
{
	int klein = samples[0];

		for (int i = 0; i < n; i++)
		{
			if(samples[i] < klein)
			{
				klein = samples[i];
			}
		}
	return klein;
}

//b)
int max(int* samples, int n)
{
	int gross = samples[0];

		for (int i = 0; i < n; i++)
		{
			if(samples[i] > gross)
			{
				gross = samples[i];
			}
		}
	return gross;
}

//c)
float mean(int* samples, int n)
{
	float mittel = 0;
	float mittelwert;

	for (int i = 0; i < n; i++)
	{
		mittel += samples[i];
	}
	mittelwert = mittel / n;

	return mittelwert;
}

//Aufgabe 2
void count (int* samples, int n)
{
	printf("samples[] = { ");
	for (int i = n-1; i >= 0; i--)
	{
		printf("%d", samples[i] );
		if (i != 0)
		{
			printf(", ");
		}
	}
	printf(" }");
}

//Aufgabe 3
int summe(int* samples, int n)
{
	int add = 0;

	for (int i = 0; i < n; i++)
	{
		add += samples[i];
	}
	return add;
}

//Aufgabe 4
void wurfel (void)
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

//Aufgabe 5
//a)
void automat (void)
{
	int muenze_e2 = 0;
	int muenze_e1 = 0;
	int muenze_c50 = 0;
	int muenze_c20 = 0;
	int muenze_c10 = 0;
	int muenze_c5 = 0;
	int muenze_c2 = 0;
	int muenze_c1 = 0;
	float wert = 0.00;

	do
	{
		printf("Bitte geben Sie einen Betrag bis 200€ mit maximal zwei Nachkommastellen ein.\n");
		scanf("%f", &wert);
	}
	while (!(wert > 0.0 && wert <= 200));
	printf("Ihre Einabe: %3.2f", wert);
	printf("\n");

	int betrag = wert * 100.0001; //Wegen Rechenfehler!

		while (betrag >= 200 && muenze_e2 < 100)
		{
				betrag = betrag - 200;
				muenze_e2++;
		}

		while (betrag >= 100 && muenze_e1 < 100)
		{
				betrag = betrag - 100;
				muenze_e1++;
		}

		while (betrag >= 50 && muenze_c50 < 100)
		{
				betrag = betrag - 50;
				muenze_c50++;
		}

		while (betrag >= 20 && muenze_c20 < 100)
		{
				betrag = betrag - 20;
				muenze_c20++;
		}

		while (betrag >= 10 && muenze_c10 < 100)
		{
				betrag = betrag - 10;
				muenze_c10++;
		}

		while (betrag >= 5 && muenze_c5 < 100)
		{
				betrag = betrag - 5;
				muenze_c5++;
		}

		while (betrag >= 2 && muenze_c2 < 100)
		{
				betrag = betrag - 2;
				muenze_c2++;
		}
			if (betrag >= 1)
			{
				betrag = betrag - 1;
				muenze_c1++;
			}

		printf("Große Münzen: %d 2e, %d 1e, %d 50c, %d 20c, %d 10c, %d 5c, %d 2c, %d 1c",
				muenze_e2, muenze_e1, muenze_c50, muenze_c20, muenze_c10, muenze_c5, muenze_c2, muenze_c1);
}

int main(void)
{
	int samples[] = { 2, 6, 8, 10, 4 };
	printf("Aufgabe 1\n");
	printf("a) ");

	printf("Minimum aus Samples = %d\n", min(samples, 5));
	printf("b) ");

	printf("Maximum aus Samples = %d\n", max(samples, 5));
	printf("c) ");

	printf("Der Mittelwert von Samples = %.1f\n", mean(samples, 5));

	printf("\nAufgabe 2\n");
	count(samples, 5);
	printf("\n");

	printf("\nAufgabe 3\n");
	printf("Die Summe ist = %d\n", summe(samples, 5));
	printf("\n");

	printf("Aufgabe 4\n");
	wurfel();

	printf("\nAufgabe 5\n");
	automat();

	return EXIT_SUCCESS;
}
