#pragma once
void swap(int* a, int* b);
int* sum(int* a, int* b);
void inputArray(int* &a, int &n);
void printArray(int* a, int n);
int* findMax(int* arr, int n);
int* findLongestAscendingSubarray(int* a, int n, int &length);
void swapArrays(int* &a, int* &b, int &na, int &nb);
int* concatenate2Arrays(int* a, int* b, int na, int nb, int &nc);
int* merge2Arrays(int* a, int* b, int na, int nb, int &nc);
void generateMatrix1(int** &a, int &length, int &width);
int** generateMatrix2(int* a, int* b, int na, int nb, int &crow, int &ccol);
void swapRows(int** a, int length, int width, int ir1, int ir2);
void swapColumns(int** a, int length, int width, int ic1, int ic2);
int** transposeMatrix(int** a, int length, int width);

int** concatenate2MatricesH(int** a, int** b, int length, int width, int &lres, int &wres);
int** concatenate2MatricesV(int** a, int** b, int length, int width, int &lres, int &wres);

bool multiple2Matrices(int**& res, int** a, int **b, int& lengthr, int& widthr, int lengtha, int widtha, int lengthb, int widthb);
int** findSubmatrix(int** a, int length, int width, int &lres, int &wres);

int LinearSearch(int* a, int n, int key);
int SentinelLinearSearch(int* a, int n, int key);
int BinarySearch(int* a, int n, int key);
int RecursiveBinarySearch(int* a, int left, int right, int key);