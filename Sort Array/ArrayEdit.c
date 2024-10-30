#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "header.h"

//main function
  //Double
void CreatDoubleArray(int len_array, double** array)
{
	*array = (double*)malloc(len_array * sizeof(double));
}

void CopyDoubleArray(int len_array, double* array, double** copy_array)
{
	int index = 0;
	*copy_array = (double*)malloc(len_array * sizeof(double));

	for (index = 0; index < len_array; ++index)
		(*copy_array)[index] = array[index];
}

void PrintDoubleArray(int len_array, double* array) // форма вывода [1; 2; 3]
{
	int index = 0;
	printf("[");
	for (index = 0; index < len_array - 1; ++index)
		printf("%lf; ", array[index]);
	printf("%lf]\n", array[len_array - 1]);
}

void FreeDoubleArray(double* array)
{
	free(array);
}

  //Int 
void CreatIntArray(int len_array, int** array)
{
	*array = (int*)malloc(len_array * sizeof(int));
}

void CopyIntArray(int len_array, int* array, int** copy_array)
{
	int index = 0;
	*copy_array = (int*)malloc(len_array * sizeof(int));

	for (index = 0; index < len_array; ++index)
		(*copy_array)[index] = array[index];
}

void PrintIntArray(int len_array, int* array) // форма вывода [1; 2; 3]
{
	int index = 0;
	printf("[");
	for (index = 0; index < len_array - 1; ++index)
		printf("%d; ", array[index]);
	printf("%d]\n", array[len_array - 1]);
}

void FreeIntArray(int* array)
{
	free(array);
}

//Time

void DelayTime(int number_of_seconds)
{
	int milli_seconds = 40 * number_of_seconds;

	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds);
}

void PrintDelay(char str[])
{
	int index = 0;
	for (index = 0; str[index] != '\0'; index++)
	{
		DelayTime(1);
		putchar(str[index]);
	}
}