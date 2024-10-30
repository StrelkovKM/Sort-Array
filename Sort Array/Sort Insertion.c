#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "header.h"

void SortArrayInsertion(int len_array, double* array)
{
	int this_index = 0, last_index = 0;
	double key;
	for (this_index = 1; this_index < len_array; ++this_index)
	{
		key = array[this_index];
		last_index = this_index - 1;

		while (last_index >= 0 && array[last_index] > key)
		{
			array[last_index + 1] = array[last_index];
			--last_index;
		}
		array[last_index + 1] = key;
	}
}