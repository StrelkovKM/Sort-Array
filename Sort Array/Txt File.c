#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "header.h"
  //double
void TxtDoubleArray(int *len_array, double** array)
{
	char counter = 0, str[255] = "";
	int index = 0, number = 0;
	FILE* enter;
	*len_array = 0;
	PrintDelayStr(
		"Enter name your file: "
	);
	scanf("%s", &str);

	enter = fopen(str, "r");
	for (counter = getc(enter); counter != EOF; counter = getc(enter))
		if (counter == '\n')
			++(*len_array);
	fclose(enter);

	*array = (double*)malloc((*len_array) * sizeof(double));

	enter = fopen(str, "r");

	for (index = 0; index < *len_array; ++index)
		fscanf(enter, "%lf\n", &((*array)[index]));

	fclose(enter);
	
}
  //Int
void TxtIntArray(int* len_array, int** array)
{
	char counter = 0, str[255] = "";
	int index = 0, number = 0;
	FILE* enter;
	*len_array = 0;
	PrintDelayStr(
		"Enter name your file: "
	);
	scanf("%s", &str);

	enter = fopen(str, "r");
	for (counter = getc(enter); counter != EOF; counter = getc(enter))
		if (counter == '\n')
			++(*len_array);
	fclose(enter);

	*array = (int*)malloc((*len_array) * sizeof(int));

	enter = fopen(str, "r");

	for (index = 0; index < *len_array; ++index)
		fscanf(enter, "%d\n", &((*array)[index]));

	fclose(enter);

}