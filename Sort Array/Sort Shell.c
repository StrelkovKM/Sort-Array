#define _CRT_SECURE_NO_WARNINGS
#define _CLOCK_PER_SEC

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "header.h"

void SortArrayShell(int len_array, double* array )
{
	int gap_index = 0, index = 0, new_index = 0;
	double temp = 0;

	for (gap_index = len_array / 2; gap_index > 0; gap_index /= 2)
	{
		for (index = gap_index; index < len_array; ++index)
		{
			temp = array[index];
			for (new_index = index; new_index >= gap_index &&
				array[new_index - gap_index] > temp; new_index -= gap_index)
			{
				array[new_index] = array[new_index - gap_index];
			}
			array[new_index] = temp;
		}
	}
}