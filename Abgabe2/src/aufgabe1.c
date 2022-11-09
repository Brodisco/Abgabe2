/*
 * aufgabe1.c
 *
 *  Created on: 09.11.2022
 *      Author: student
 */


#include <stdio.h>
#include <stdlib.h>


// Aufgabe 1
int min(int* samples, int n)
{
	int counter = 0;
	for(int i = 0; i != n; i++)
	{
		counter = 0;
		for(int y = 0; y != n; y++)
		{
			if(i == y)
			{
			}
			else
			{
				if(samples[i] < samples[y])
				{
					counter++;
				}
			}
			if(counter == n-1)
			{
				return samples[i];
			}
		}
	}
	return 0;
}

int max(int* samples, int n)

{
	int counter = 0;
		for(int i = 0; i != n; i++)
		{
			counter = 0;
			for(int y = 0; y != n; y++)
			{
				if(i == y)
				{
				}
				else
				{
					if(samples[i] > samples[y])
					{
						counter++;
					}
				}
				if(counter == n-1)
				{
					return samples[i];
				}
			}
		}
		return 0;
}

float mean(int* samples, int n)
{

	float mean1;
	for(int i = 0; i < n; i++)
	{
		mean1 += samples[i];
	}
	return mean1/n;

}
