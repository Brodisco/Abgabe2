/*
 * aufgabe1.c
 *
 *  Created on: 01.11.2022
 *      Author: student
 */
#include <stdio.h>
#include <stdlib.h>
#include "abgabe2.h"

int min(int *samples, int n)
{
	int result = samples[0];

	for (int i = 0; i < n; i++)
	{
		if (result > samples[i])
		{
			result = samples[i];
		}
	}

	return result;
}

int max(int *samples, int n)
{
	int result = samples[0];

	for (int i = 0; i < n; i++)
	{
		if (result < samples[i])
		{
			result = samples[i];
		}
	}

	return result;
}

float mean(int *samples, int n)
{
	float result = (int)printSumIntArray(samples, n);

	return (result / n);
}

