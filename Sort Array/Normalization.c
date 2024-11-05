#define _CRT_SECURE_NO_WARNINGS
#define _CLOCK_PER_SEC

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "header.h"

double FirstNormArray(int len_array, double* array)
{
	int index = 0;
	double sum = 0;

	for (index = 0; index < len_array; ++index)
		sum += fabs(array[index]);
	return sum;
}

double SecondNormArray(int len_array, double* array)
{
	int index = 0;
	double sum = 0;

	for (index = 0; index < len_array; ++index)
		sum += pow(array[index], 2);
	return pow(sum, 0.5);
}

double HelderNormArray(int len_array, double* array)
{
	int index = 0;
	double sum = 0;

	for (index = 0; index < len_array; ++index)
		sum += pow(array[index], len_array);
	return pow(sum, 1.0/len_array);
}

double InfinityNormArray(int len_array, double* array)
{
	int index = 0;
	double max_number = 0;
	for (index = 0; index < len_array; ++index)
	{
		if (fabs(max_number) < fabs(array[index]))
			max_number = array[index];
	}

	return max_number;
}

void NormalizationArray(int len_array, double* array, double** normal_array)
{
  *normal_array = (double*)malloc(len_array*sizeof(double));
	double len_vector = 0;
	int index = 0;

	len_vector = SecondNormArray(len_array, array);
	
	for (index = 0; index < len_array; ++index)
	{
		(*normal_array)[index] = array[index] / len_vector;
	}
}