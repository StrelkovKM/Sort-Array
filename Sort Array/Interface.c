#define _CRT_SECURE_NO_WARNINGS
#define _CLOCK_PER_SEC

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "header.h"

void Introduction(void)
{
	PrintDelayStr("Hello user, this is a program designed to sort numbers and to normalize vectors.\n");
}

void InputTask(int* enter_code)
{
	PrintDelayStr(
		"1) Sorting numbers\n"
		"2) Normalization of the vector\n"
		">Press any other key to exit the program\n"
		"Enter number: "
	);
	scanf("%d", enter_code);
	system("cls");
}

void InputSelection(int *enter_code)
{
	PrintDelayStr(
		"Select the type of data entry:\n"
		"1) Console input\n"
		"2) Random data\n"
		"3) Read .txt file\n"
		">Press any other key to exit the program\n"
		"Enter number: "
	);
	scanf("%d", enter_code);
	system("cls");
}

void ConsoleWaySort(void)
{
	int len_array = 0, index = 0;
	double* array_d, * copy_array_d;
	int* array_i, * copy_array_i;
	clock_t begin = 0, end = 0;
	double time_spent = 0;
	FILE* IntFile;
	FILE* DoubleFile;

	PrintDelayStr("All sort to compare the performance time:\n");
	ConsoleDoubleArray(&len_array, &array_d);
	PrintDelayStr("\nYour array of numbers:\n");
	PrintDoubleArray(len_array, array_d);

	PrintDelayStr("\n1) Sort Bubble:\n");
	CopyDoubleArray(len_array, array_d, &copy_array_d);
	begin = clock();
	SortArrayBubble(len_array, copy_array_d);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	PrintDoubleArray(len_array, copy_array_d);
	PrintTime(time_spent);
	FreeDoubleArray(copy_array_d);

	PrintDelayStr("\n2) Sort Selection:\n");
	CopyDoubleArray(len_array, array_d, &copy_array_d);
	begin = clock();
	SortArraySelection(len_array, copy_array_d);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	PrintDoubleArray(len_array, copy_array_d);
	PrintTime(time_spent);
	FreeDoubleArray(copy_array_d);

	PrintDelayStr("\n3) Sort Insertion:\n");
	CopyDoubleArray(len_array, array_d, &copy_array_d);
	begin = clock();
	SortArrayInsertion(len_array, copy_array_d);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	PrintDoubleArray(len_array, copy_array_d);
	PrintTime(time_spent);
	FreeDoubleArray(copy_array_d);

	PrintDelayStr("\n4) Sort Marge:\n");
	CopyDoubleArray(len_array, array_d, &copy_array_d);
	begin = clock();
	SortArrayMerge(copy_array_d, 0, (len_array - 1));
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	PrintDoubleArray(len_array, copy_array_d);
	PrintTime(time_spent);
	FreeDoubleArray(copy_array_d);

	PrintDelayStr("\n5) Sort Quick(Hoara):\n");
	CopyDoubleArray(len_array, array_d, &copy_array_d);
	begin = clock();
	SortArrayQuick(copy_array_d, 0, (len_array - 1));
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	PrintDoubleArray(len_array, copy_array_d);
	PrintTime(time_spent);
	FreeDoubleArray(copy_array_d);

	PrintDelayStr("\n6) Sort Shell:\n");
	CopyDoubleArray(len_array, array_d, &copy_array_d);
	begin = clock();
	SortArrayShell(len_array, copy_array_d);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	PrintDoubleArray(len_array, copy_array_d);
	PrintTime(time_spent);
	
	DoubleFile = fopen("DoubleFile.txt", "w");
	for (index = 0; index < len_array; ++index)
		fprintf(DoubleFile, "%lf\n", copy_array_d[index]);
	fclose(DoubleFile);
	PrintDelayStr(
		"\nYour array is sorted and written to a file: DoubleFile.txt\n"
		"__________________________________________________________\n"
	);
	FreeDoubleArray(copy_array_d);

	FreeDoubleArray(array_d);

	PrintDelayStr(
		"\nSort Counting:\n"
		"This sorting only supports integers greater than 0\n"
	);
	ConsoleIntArray(&len_array, &array_i);
	PrintDelayStr("\nYour array of numbers:\n");
	PrintIntArray(len_array, array_i);
	CopyIntArray(len_array, array_i, &copy_array_i);
	begin = clock();
	SortArrayCounting(len_array, copy_array_i);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	PrintDelayStr("\n7) Sort Counting:\n");
	PrintIntArray(len_array, copy_array_i);
	PrintTime(time_spent);
	IntFile = fopen("IntFile.txt", "w");
	for (index = 0; index < len_array; ++index)
		fprintf(IntFile, "%d\n", copy_array_i[index]);
	fclose(IntFile);
	PrintDelayStr(
		"\nYour array is sorted and written to a file: IntFile.txt\n"
		"_______________________________________________________\n"
	);
	FreeIntArray(copy_array_i);

	FreeIntArray(array_i);

	system("pause");
	system("cls");
}

void RandomWaySort(void)
{
	int len_array = 0, min_number_i = 0, max_number_i = 0, index = 0;
	double* array_d, * copy_array_d, min_number_d = 0, max_number_d = 0;
	int* array_i, * copy_array_i;
	clock_t begin = 0, end = 0;
	double time_spent = 0;
	FILE* IntFile;
	FILE* DoubleFile;

	PrintDelayStr("All sort to compare the performance time:\n");
	RandomDoubleArray(&len_array, &array_d, &min_number_d, &max_number_d);
	PrintDelayStr("\nYour array of numbers:\n");
	PrintDoubleArray(len_array, array_d);

	PrintDelayStr("\n1) Sort Bubble:\n");
	CopyDoubleArray(len_array, array_d, &copy_array_d);
	begin = clock();
	SortArrayBubble(len_array, copy_array_d);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	PrintDoubleArray(len_array, copy_array_d);
	PrintTime(time_spent);
	FreeDoubleArray(copy_array_d);

	PrintDelayStr("\n2) Sort Selection:\n");
	CopyDoubleArray(len_array, array_d, &copy_array_d);
	begin = clock();
	SortArraySelection(len_array, copy_array_d);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	PrintDoubleArray(len_array, copy_array_d);
	PrintTime(time_spent);
	FreeDoubleArray(copy_array_d);

	PrintDelayStr("\n3) Sort Insertion:\n");
	CopyDoubleArray(len_array, array_d, &copy_array_d);
	begin = clock();
	SortArrayInsertion(len_array, copy_array_d);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	PrintDoubleArray(len_array, copy_array_d);
	PrintTime(time_spent);
	FreeDoubleArray(copy_array_d);

	PrintDelayStr("\n4) Sort Marge:\n");
	CopyDoubleArray(len_array, array_d, &copy_array_d);
	begin = clock();
	SortArrayMerge(copy_array_d, 0, (len_array - 1));
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	PrintDoubleArray(len_array, copy_array_d);
	PrintTime(time_spent);
	FreeDoubleArray(copy_array_d);

	PrintDelayStr("\n5) Sort Quick(Hoara):\n");
	CopyDoubleArray(len_array, array_d, &copy_array_d);
	begin = clock();
	SortArrayQuick(copy_array_d, 0, (len_array - 1));
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	PrintDoubleArray(len_array, copy_array_d);
	PrintTime(time_spent);
	FreeDoubleArray(copy_array_d);

	PrintDelayStr("\n6) Sort Shell:\n");
	CopyDoubleArray(len_array, array_d, &copy_array_d);
	begin = clock();
	SortArrayShell(len_array, copy_array_d);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	PrintDoubleArray(len_array, copy_array_d);
	PrintTime(time_spent);

	DoubleFile = fopen("DoubleFile.txt", "w");
	for (index = 0; index < len_array; ++index)
		fprintf(DoubleFile, "%lf\n", copy_array_d[index]);
	fclose(DoubleFile);
	PrintDelayStr(
		"\nYour array is sorted and written to a file: DoubleFile.txt\n"
		"__________________________________________________________\n"
	);

	FreeDoubleArray(copy_array_d);

	FreeDoubleArray(array_d);

	PrintDelayStr(
		"\nSort Counting:\n"
		"This sorting only supports integers greater than 0\n"
	);
	RandomIntArray(&len_array, &array_i, &min_number_i, &max_number_i);
	PrintDelayStr("\nYour array of numbers:\n");
	PrintIntArray(len_array, array_i);
	CopyIntArray(len_array, array_i, &copy_array_i);
	begin = clock();
	SortArrayCounting(len_array, copy_array_i);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	PrintDelayStr("\n7) Sort Counting:\n");
	PrintIntArray(len_array, copy_array_i);
	PrintTime(time_spent);

	IntFile = fopen("IntFile.txt", "w");
	for (index = 0; index < len_array; ++index)
		fprintf(IntFile, "%d\n", copy_array_i[index]);
	fclose(IntFile);
	PrintDelayStr(
		"\nYour array is sorted and written to a file: IntFile.txt\n"
		"_______________________________________________________\n"
	);

	FreeIntArray(copy_array_i);

	FreeIntArray(array_i);

	system("pause");
	system("cls");
}

void TxtWaySort(void)
{
	int len_array = 0, index = 0;
	double* array_d, * copy_array_d;
	int* array_i, * copy_array_i;
	clock_t begin = 0, end = 0;
	double time_spent = 0;
	FILE* IntFile;
	FILE* DoubleFile;

	PrintDelayStr("All sort to compare the performance time:\n");
	TxtDoubleArray(&len_array, &array_d);
	PrintDelayStr("\nYour array of numbers:\n");
	PrintDoubleArray(len_array, array_d);

	PrintDelayStr("\n1) Sort Bubble:\n");
	CopyDoubleArray(len_array, array_d, &copy_array_d);
	begin = clock();
	SortArrayBubble(len_array, copy_array_d);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	PrintDoubleArray(len_array, copy_array_d);
	PrintTime(time_spent);
	FreeDoubleArray(copy_array_d);

	PrintDelayStr("\n2) Sort Selection:\n");
	CopyDoubleArray(len_array, array_d, &copy_array_d);
	begin = clock();
	SortArraySelection(len_array, copy_array_d);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	PrintDoubleArray(len_array, copy_array_d);
	PrintTime(time_spent);
	FreeDoubleArray(copy_array_d);

	PrintDelayStr("\n3) Sort Insertion:\n");
	CopyDoubleArray(len_array, array_d, &copy_array_d);
	begin = clock();
	SortArrayInsertion(len_array, copy_array_d);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	PrintDoubleArray(len_array, copy_array_d);
	PrintTime(time_spent);
	FreeDoubleArray(copy_array_d);

	PrintDelayStr("\n4) Sort Marge:\n");
	CopyDoubleArray(len_array, array_d, &copy_array_d);
	begin = clock();
	SortArrayMerge(copy_array_d, 0, (len_array - 1));
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	PrintDoubleArray(len_array, copy_array_d);
	PrintTime(time_spent);
	FreeDoubleArray(copy_array_d);

	PrintDelayStr("\n5) Sort Quick(Hoara):\n");
	CopyDoubleArray(len_array, array_d, &copy_array_d);
	begin = clock();
	SortArrayQuick(copy_array_d, 0, (len_array - 1));
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	PrintDoubleArray(len_array, copy_array_d);
	PrintTime(time_spent);
	FreeDoubleArray(copy_array_d);

	PrintDelayStr("\n6) Sort Shell:\n");
	CopyDoubleArray(len_array, array_d, &copy_array_d);
	begin = clock();
	SortArrayShell(len_array, copy_array_d);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	PrintDoubleArray(len_array, copy_array_d);
	PrintTime(time_spent);

	DoubleFile = fopen("DoubleFile.txt", "w");
	for (index = 0; index < len_array; ++index)
		fprintf(DoubleFile, "%lf\n", copy_array_d[index]);
	fclose(DoubleFile);
	PrintDelayStr(
		"\nYour array is sorted and written to a file: DoubleFile.txt\n"
		"__________________________________________________________\n"
	);

	FreeDoubleArray(copy_array_d);

	FreeDoubleArray(array_d);

	PrintDelayStr(
		"\nSort Counting:\n"
		"This sorting only supports integers greater than 0\n"
	);
	TxtIntArray(&len_array, &array_i);
	PrintDelayStr("\nYour array of numbers:\n");
	PrintIntArray(len_array, array_i);
	CopyIntArray(len_array, array_i, &copy_array_i);
	begin = clock();
	SortArrayCounting(len_array, copy_array_i);
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	PrintDelayStr("\n7) Sort Counting:\n");
	PrintIntArray(len_array, copy_array_i);
	PrintTime(time_spent);

	IntFile = fopen("IntFile.txt", "w");
	for (index = 0; index < len_array; ++index)
		fprintf(IntFile, "%d\n", copy_array_i[index]);
	fclose(IntFile);
	PrintDelayStr(
		"\nYour array is sorted and written to a file: IntFile.txt\n"
		"_______________________________________________________\n"
	);

	FreeIntArray(copy_array_i);

	FreeIntArray(array_i);

	system("pause");
	system("cls");
}

void ConsoleWayNorm(void)
{
	int len_array = 0;
	double* array_d, * normal_vector;
	PrintDelayStr(
		"Normalization of the vector:\n"
		"____________________________\n"
	);
	ConsoleDoubleArray(&len_array, &array_d);
	PrintDelayStr(
		"____________________________\n"
		"\nYour vector:"
	);
	PrintDoubleArray(len_array, array_d);
	PrintDelayStr(
		"____________________________\n"
	);
	PrintDelayStr("The first norm of the vector: ");
	PrintDelayDouble(FirstNormArray(len_array, array_d));

	PrintDelayStr("The second norm of the vector: ");
	PrintDelayDouble(SecondNormArray(len_array, array_d));

	PrintDelayStr("The Helder norm of the vector: ");
	PrintDelayDouble(HelderNormArray(len_array, array_d));

	PrintDelayStr("The normalized vector: ");
	NormalizationArray(len_array, array_d, &normal_vector);
	PrintDoubleArray(len_array, normal_vector);

	FreeDoubleArray(array_d);
	FreeDoubleArray(normal_vector);
	system("pause");
	system("cls");
}

void RandomWayNorm(void)
{
	int len_array = 0;
	double* array_d, * normal_vector;
	double min_number_d = 0, max_number_d = 0;
	PrintDelayStr(
		"Normalization of the vector:\n"
		"____________________________\n"
	);
	RandomDoubleArray(&len_array, &array_d, &min_number_d, &max_number_d);
	PrintDelayStr(
		"____________________________\n"
		"\nYour vector:"
	);
	PrintDoubleArray(len_array, array_d);
	PrintDelayStr(
		"____________________________\n"
	);
	PrintDelayStr("The first norm of the vector: ");
	PrintDelayDouble(FirstNormArray(len_array, array_d));

	PrintDelayStr("The second norm of the vector: ");
	PrintDelayDouble(SecondNormArray(len_array, array_d));

	PrintDelayStr("The Helder norm of the vector: ");
	PrintDelayDouble(HelderNormArray(len_array, array_d));

	PrintDelayStr("The normalized vector: ");
	NormalizationArray(len_array, array_d, &normal_vector);
	PrintDoubleArray(len_array, normal_vector);

	FreeDoubleArray(array_d);
	FreeDoubleArray(normal_vector);
	system("pause");
	system("cls");
}
void TxtWayNorm(void)
{
	int len_array = 0;
	double* array_d, * normal_vector;
	PrintDelayStr(
		"Normalization of the vector:\n"
		"____________________________\n"
	);
	TxtDoubleArray(&len_array, &array_d);
	PrintDelayStr(
		"____________________________\n"
		"\nYour vector:"
	);
	PrintDoubleArray(len_array, array_d);
	PrintDelayStr(
		"____________________________\n"
	);
	PrintDelayStr("The first norm of the vector: ");
	PrintDelayDouble(FirstNormArray(len_array, array_d));

	PrintDelayStr("The second norm of the vector: ");
	PrintDelayDouble(SecondNormArray(len_array, array_d));

	PrintDelayStr("The Helder norm of the vector: ");
	PrintDelayDouble(HelderNormArray(len_array, array_d));

	PrintDelayStr("The normalized vector: ");
	NormalizationArray(len_array, array_d, &normal_vector);
	PrintDoubleArray(len_array, normal_vector);

	FreeDoubleArray(array_d);
	FreeDoubleArray(normal_vector);
	system("pause");
	system("cls");
}
int CheckCode(int enter_code, int count)
{
	int code = 1;
	for (code = 1; code < count + 1; ++code)
	{
		if (enter_code == code) return 1;
	}
	return 0;
}