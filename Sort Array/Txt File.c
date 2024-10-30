#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "header.h"

void TxtDoubleArray(int *len_array, double** array)
{
	char counter = 0;
	int index = 0, number = 0;
	FILE* enter;
	char str[255] = "";
	*len_array = 0;
	PrintDelay(
		"Select which file you want to use:\n"
		"1) Your file\n"
		"2) Edit the file attached to the code\n"
		"Enter number: "
	);
	scanf("%d", number);
	switch (number)
	{

	case 1:
	{
		enter = fopen("FileEnter.txt", "r");
		for (counter = getc(enter); counter != EOF; counter = getc(enter))
			if (counter == '\n')
				++(*len_array);
		fclose(enter);

		*array = (double*)malloc((*len_array) * sizeof(double));

		enter = fopen("FileEnter.txt", "r");

		for (index = 0; index < *len_array; ++index)
			fscanf(enter, "%lf\n", &((*array)[index]));

		fclose(enter);
	}
	case 2:
	{
		PrintDelay("Enter name your file:");
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
	default:
		break;
	}
}
