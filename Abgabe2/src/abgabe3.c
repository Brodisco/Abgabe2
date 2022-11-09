/*
 * abgabe3.c
 *
 *  Created on: 01.11.2022
 *      Author: student
 */
#include <stdio.h>
#include <stdlib.h>
#include "abgabe2.h"

int printSumIntArray(int *samples, int n)
{
	int result = 0;

	for (int i = 0; i < n; i++)
	{
		result += samples[i];
	}

	return result;
}
