/*
 * abgabe2.h
 *
 *  Created on: 01.11.2022
 *      Author: student
 */

#ifndef ABGABE2_H_
#define ABGABE2_H_

/*
 * Aufgabe 1
 */
int min(int *samples, int n);
int max(int *samples, int n);
float mean(int *samples, int n);

/*
 * Aufgabe 2
 */
void printIntArray(int *samples, int n);

/*
 *  Aufgabe 3
 */
int printSumIntArray(int *samples, int n);

/*
 *  Aufgabe 4
 */
void profBWurfel();

/*
 *  Aufgabe 5
 */
int *smartCoinMachine();
void sillyCoinMachine();
int *rebaseOutput(int coinType, int maxCoins, int *output, int *coins);

#endif /* ABGABE2_H_ */
