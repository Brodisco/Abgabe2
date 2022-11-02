/*
 * aufgabe2.c
 *
 *  Created on: 01.11.2022
 *      Author: student
 */
#include <stdio.h>
#include <stdlib.h>
#include "abgabe2.h"

void printIntArray(int *samples, int n)
{
	printf("samples[] = {");
	for (int i = (n - 1); i >= 0; i--)
	{
		printf(" %d,", *(samples + i));
	}
	printf("}\n");
}
