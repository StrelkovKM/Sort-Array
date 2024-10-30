#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "header.h"

void SortArrayCounting( int len_array, int* array)
{
	long long int M = 0;
	int index = 0;
	int* output_array;

	for (index = 0; index < len_array; ++index)
	{
		if (array[index] > M)
			M = array[index];
	}

	int* count_array = (int*)calloc(M + 1, sizeof(int));

	for (index = 0; index < len_array; ++index)
	{
		count_array[array[index]]++;
	}

	for (index = 1; index <= M; ++index)
	{
		count_array[index] += count_array[index - 1];
	}

	CreatIntArray(len_array, &output_array);

	for (index = len_array - 1; index >= 0; --index)
	{
		output_array[count_array[array[index]] - 1] = array[index];
		--count_array[array[index]];
	}

	for (index = 0; index < len_array; ++index)
	{
		array[index] = output_array[index];
	}
	FreeIntArray(count_array);
	FreeIntArray(output_array);
}