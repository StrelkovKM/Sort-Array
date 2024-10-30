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
	double scan_number = 0;
	char enter_scan[] = "Enter number:\t";
	char enter_number[] = "Enter the number of numbers to sort:\t";

	PrintDelay(enter_number);
	scanf("%d", len_array);

	*array = (double*)malloc(*len_array * sizeof(double));

	for (index = 0; index < *len_array; ++index)
	{
		PrintDelay(enter_scan);
		scanf("%lf", &scan_number);
		(*array)[index] = scan_number;
	}
}
 //Int
void ConsoleIntArray(int len_array, int* array)
{
	int scan_number = 0;

	for (index = 0; index < len_array; ++index)
	{
		printf("Enter number:\t");
		scanf("%d", &scan_number);
		array[index] = scan_number;
	}
}
