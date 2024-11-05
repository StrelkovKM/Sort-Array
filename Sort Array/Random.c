#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "header.h"

//random
  //double
void RandomDoubleArray(int *len_array, double** array, double* min_random, double* max_random)
{
	int index = 0;

	PrintDelayStr("\nEnter the count of generated numbers:\t");
	scanf("%d", len_array);

	PrintDelayStr("Enter the minimum number to generate:\t");
	scanf("%lf", min_random);

	PrintDelayStr("Enter the maximum number to generate:\t");
	scanf("%lf", max_random);

	

	*array = (double*)malloc(*len_array * sizeof(double));

	for (index = 0; index < *len_array; ++index)
		(*array)[index] = MakeRandomDouble(*min_random, *max_random);
}

double MakeRandomDouble(double min_random, double max_random)
{
	double first_random = 0, random_number = 0, second_random = 0;
	int randomization = 0;
	randomization = rand();
	first_random = (double)randomization / RAND_MAX;
	second_random = first_random * (max_random - min_random);
	random_number = second_random + min_random;
	return random_number;

}

  // Int

void RandomIntArray(int* len_array, int** array, int* min_random, int* max_random)
{
	int index = 0;

	PrintDelayStr("\nEnter the count of generated numbers:\t");
	scanf("%d", len_array);

	PrintDelayStr("Enter the minimum number to generate:\t");
	scanf("%d", min_random);

	PrintDelayStr("Enter the maximum number to generate:\t");
	scanf("%d", max_random);



	*array = (int*)malloc(*len_array * sizeof(int));

	for (index = 0; index < *len_array; ++index)
		(*array)[index] = MakeRandomInt(*min_random, *max_random);
}

int MakeRandomInt(int min_random, int max_random)
{
	int first_random = 0, random_number = 0, second_random = 0;
	int randomization = 0;
	random_number = min_random + rand() % (max_random - min_random + 1);
	return random_number;
}