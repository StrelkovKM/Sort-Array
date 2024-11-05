#define _CRT_SECURE_NO_WARNINGS
#define _CLOCK_PER_SEC

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "header.h"

void SortArraySelection(int len_array, double* array)
{
	int this_index = 0, next_index = 0, min_index = 0;

	for (this_index = 0; this_index < len_array - 1; ++this_index)
	{
		min_index = this_index;
		for (next_index = this_index + 1; next_index < len_array; ++next_index)
		{
			if (array[next_index] < array[min_index])
				min_index = next_index;
		}
		SwapElementArray(array, min_index, this_index);
	}
}