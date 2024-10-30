#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "header.h"

int PartitionArray(double* array, int low, int high)
{
	double part = array[low];
	int low_index = low, high_index = high;

	while (low_index < high_index)
	{
		while (array[low_index] <= part && low_index <= high - 1)
		{
			++low_index;
		}

		while (array[high_index] > part && high_index >= low + 1)
		{
			--high_index;
		}

		if (low_index < high_index)
		{
			SwapElementArray(array, low_index, high_index);
		}
	}
	SwapElementArray(array, low, high_index);

	return high_index;
}

void SortArrayQuick(double* array, int low, int high)
{
	int pi = 0;
	if (low < high)
	{
		pi = PartitionArray(array, low, high);
		SortArrayQuick(array, low, pi - 1);
		SortArrayQuick(array, pi + 1, high);
	}	
}