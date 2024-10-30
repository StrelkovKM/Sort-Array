#ifndef __HEADER_H__
#define __HEADER_H__

//Function.c
  //Double 
void CreatDoubleArray(int len_array, double** array);
void CopyDoubleArray(int len_array, double* array, double** copy_array);
void PrintDoubleArray(int len_array, double* array);
void FreeDoubleArray(double* array);
  //Int
void CreatIntArray(int len_array, int** array);
void CopyIntArray(int len_array, int* array, int** copy_array);
void PrintIntArray(int len_array, int* array);
void FreeIntArray(int* array);
  //Time
void DelayTime(int number_of_seconds);
void PrintDelay(char str[]);

//Console
   //Double
void ConsoleDoubleArray(int* len_array, double** array);
   //Int
void ConsoleIntArray(int len_array, int* array);
  
//Random
   //Double
double MakeRandomDouble(double min_number, double max_number);
void RandomDoubleArray(int* len_array, double** array, double* min_random, double* max_random);
   //Int
void RandomIntArray(int* len_array, int** array, int* min_random, int* max_random);
int MakeRandomInt(int min_random, int max_random);

//Txt File.c
void TxtDoubleArray(int* len_array, double** array);


//Sort Bubble.c
void SwapElementArray(double* array, int this_index, int next_index);
void SortArrayBubble(int len_array, double* array);

//Sort Selection.c
void SortArraySelection(int len_array, double* array);

//Sort Insertion.c
void SortArrayInsertion(int len_array, double* array);

//Sort Merge.c
void MergeArrays(double* array, int left, int middle, int right);
void SortArrayMarge(double* array, int left, int right);

//Sort Quick.c (Hoara)
int PartitionArray(double* array, int low, int high);
void SortArrayQuick(double* array, int low, int high);

//Sort Shell.c
void SortArrayShell(int len_array, double* array);

//Sort Counting.c
void SortArrayCounting(int len_array, int* array);


// Interface
void Introduction(void);

#endif //!__HEADER_H__