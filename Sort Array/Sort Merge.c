#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "header.h"

void MergeArrays(double* array, int left, int middle, int right)
{
	int left_index = 0, right_index = 0, key = 0;
	int len_left_array = middle - left + 1;
	int len_right_array = right - middle;
	double *left_array, *right_array;

	CreatDoubleArray(len_left_array, &left_array);
	CreatDoubleArray(len_right_array, &right_array);

	for (left_index = 0; left_index < len_left_array; ++left_index)
		left_array[left_index] = array[left + left_index];
	for (right_index = 0; right_index < len_right_array; ++right_index)
		right_array[right_index] = array[middle + 1 + right_index];

	left_index = 0;
	right_index = 0;
	key = left;

	while (left_index < len_left_array && right_index < len_right_array)
	{
		if (left_array[left_index] <= right_array[right_index])
		{
			array[key] = left_array[left_index];
			++left_index;
		}
		else
		{
			array[key] = right_array[right_index];
			++right_index;
		}
		++key;
	}

	while (left_index < len_left_array)
	{
		array[key] = left_array[left_index];
		++left_index;
		++key;
	}

	while (right_index < len_right_array)
	{
		array[key] = right_array[right_index];
		++right_index;
		++key;
	}

	FreeDoubleArray(right_array);
	FreeDoubleArray(left_array);
}

void SortArrayMarge(double* array, int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;

		SortArrayMarge(array, left, middle);
		SortArrayMarge(array, middle + 1, right);

		MergeArrays(array, left, middle, right);


	}
}