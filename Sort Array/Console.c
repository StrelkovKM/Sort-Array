#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "header.h"

int index = 0;

	//Double
void ConsoleDoubleArray(int *len_array, double** array)
{
	double scan_number = 0;;

	PrintDelayStr("Enter the number of numbers:\t");
	scanf("%d", len_array);

	*array = (double*)malloc(*len_array * sizeof(double));

	for (index = 0; index < *len_array; ++index)
	{
		PrintDelayStr("Enter number:\t");
		scanf("%lf", &scan_number);
		(*array)[index] = scan_number;
	}
}
 //Int
void ConsoleIntArray(int *len_array, int** array)
{
	int scan_number = 0;

	PrintDelayStr("Enter the number of numbers to sort:\t");
	scanf("%d", len_array);

	*array = (int*)malloc(*len_array * sizeof(int));

	for (index = 0; index < *len_array; ++index)
	{
		printf("Enter number:\t");
		scanf("%d", &scan_number);
		(*array)[index] = scan_number;
	}
}
