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
	srand(time(NULL));

	char wurfel1 [] [20] = {"Lehm" , "Holz", "Schaf", "Erz", "Getreide", "Gold"};
	char wurfel2 [] [20] = {"Sonne", "Mühle", "Ritter", "Fragezeichen", "Räuber", "Räuber"};

	int r1 = rand() % 6;
	int r2 = rand() % 6;

	printf(" Wurfel 1: %s ", wurfel1[r1]);
	printf(" Wurfel 2: %s", wurfel2[r2]);
}

//Aufgabe 5
void automat (void)
{

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
	printf("Für ein Wurf drücken Sie die Eingabetaste. Wenn Sie das Programm beenden möchten, drücken Sie die Taste q.\n");
	char temp = 0;
	int i = 1;
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
		wurfel ();
	}

	printf("\nAufgabe 5\n");
	float betrag;
	printf("Geben Sie ihr gewünschte Geldbetrag ein: ");
	scanf("%f", &betrag);
	automat();

	return EXIT_SUCCESS;
}
