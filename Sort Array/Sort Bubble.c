#define _CRT_SECURE_NO_WARNINGS
#define _CLOCK_PER_SEC

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "header.h"

void SwapElementArray(double* array, int this_index, int next_index)
{
	double swap = 0;
	swap = array[this_index];
	array[this_index] = array[next_index];
	array[next_index] = swap;
}

void SortArrayBubble(int len_array, double* array)
{
	int this_index = 0, next_index = 0;

	for (this_index = 0; this_index < len_array - 1; ++this_index) 
	{
		for (next_index = 0; next_index < len_array - this_index - 1; ++next_index)
			if (array[next_index] > array[next_index + 1])
			{
				SwapElementArray(array, next_index, next_index + 1);
			}
	}
}