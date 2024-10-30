#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "header.h"


int main()
{
	double *array_d, *copy_array_d;
	int* array_i, * copy_array_i, * min_number, * max_number;
	int len_array = 0;
	

	Introduction();
	TxtDoubleArray(&len_array, &array_d);
	//RandomDoubleArray(&len_array, &array_d, &min_number, &max_number);
	//ConsoleDoubleArray(&len_array, &array_d);
	
	//Sort Bubble
	printf("Sort Bubble\n");
	CopyDoubleArray(len_array, array_d, &copy_array_d);
	PrintDoubleArray(len_array, array_d);
	SortArrayBubble(len_array, copy_array_d);
	PrintDoubleArray(len_array, copy_array_d);
	FreeDoubleArray(copy_array_d);

	//Sort Selection
	printf("Sort Selection\n");
	CopyDoubleArray(len_array, array_d, &copy_array_d);
	PrintDoubleArray(len_array, array_d);
	SortArraySelection(len_array, copy_array_d);
	PrintDoubleArray(len_array, copy_array_d);
	FreeDoubleArray(copy_array_d);
	
	//Sort Insertion
	printf("Sort Insertion\n");
	CopyDoubleArray(len_array, array_d, &copy_array_d);
	PrintDoubleArray(len_array, array_d);
	SortArrayInsertion(len_array, copy_array_d);
	PrintDoubleArray(len_array, copy_array_d);
	FreeDoubleArray(copy_array_d);

	//Sort Marge
	printf("Sort Marge\n");
	CopyDoubleArray(len_array, array_d, &copy_array_d);
	PrintDoubleArray(len_array, array_d);
	SortArrayMarge(copy_array_d, 0, (len_array - 1));
	PrintDoubleArray(len_array, copy_array_d);
	FreeDoubleArray(copy_array_d);

	//Sort Quick
	printf("Sort Quick\n");
	CopyDoubleArray(len_array, array_d, &copy_array_d);
	PrintDoubleArray(len_array, array_d);
	SortArrayQuick(copy_array_d, 0, (len_array - 1));
	PrintDoubleArray(len_array, copy_array_d);
	FreeDoubleArray(copy_array_d);

	//Sort Shell
	printf("Sort Shell\n");
	CopyDoubleArray(len_array, array_d, &copy_array_d);
	PrintDoubleArray(len_array, array_d);
	SortArrayShell(len_array, copy_array_d);
	PrintDoubleArray(len_array, copy_array_d);
	FreeDoubleArray(copy_array_d);

/*
	printf("Enter the number of numbers to sort:\t");
	scanf("%d", &len_array);

	ConsoleIntInput(len_array, array_i);
	//Sort Counting
	printf("Sort Counting\n");
	CopyIntArray(len_array, array_i, &copy_array_i);
	PrintIntArray(len_array, array_i);
	SortArrayCounting(len_array, copy_array_i);
	PrintIntArray(len_array, copy_array_i);
	FreeIntArray(copy_array_i);
	*/

	FreeDoubleArray(array_d);
	//FreeDoubleArray(array_i);
	system("pause");
	system("cls");
}