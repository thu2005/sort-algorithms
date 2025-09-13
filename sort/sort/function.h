#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <cmath>
#include <ctime>
#include <vector>

#define ll long long
using namespace std;

template <class T>
void HoanVi(T& a, T& b);
void GenerateRandomData(int *a, int n);
void GenerateSortedData(int *a, int n);
void GenerateReverseData(int *a, int n);
void GenerateNearlySortedData(int *a, int n);
void GenerateData(int *a, int n, int dataType);

// SORT
void insertionSort(int* arr, int n);
void heapify(int* arr, int n, int i);
void heapSort(int* arr, int n);
void shellSort(int* arr, int n);
void flashSort(int* arr, int n);
void countingSort(int* arr, int n);
void shakerSort(int* arr, int n);
void bubbleSort(int* arr, int n);
void selectionSort(int* arr, int n);
void quickSort(int* arr, int left, int right);
void merge(int* arr, int nb, int nc, int k, int* b, int* c);
void mergeSort(int* arr, int n);
int getMax(int* arr, int n);
void countSort(int* arr, int n, int exp);
void radixSort(int* arr, int n);


// COUNT COMPARISONS
void insertionSort_withCount(int* arr, int n, ll& count_compare);
void heapify_withCount(int* arr, int n, int i, ll& count_compare);
void heapSort_withCount(int* arr, int n, ll& count_compare);
void shellSort_withCount(int* arr, int n, long long& count_compare);
void flashSort_withCount(int* arr, int n, long long& count_compare);
void countingSort_withCount(int* arr, int n, ll& count_compare);
void shakerSort_withCount(int* arr, int n, ll& count_compare);
void bubbleSort_withCount(int* arr, int n, ll& count_compare);
void selectionSort_withCount(int* arr, int n, ll& count_compare);
void quickSort_withCount(int* arr, int left, int right, ll& count_compare);
void merge_withCount(int* arr, int nb, int nc, int k, int* b, int* c, ll& count_compare);
void mergeSort_withCount(int* arr, int n, ll& count_compare);
void getMax_withCount(int* arr, int n, int& mx, ll& count_compare);
void countSort_withCount(int* arr, int n, int exp, ll& count_compare);
void radixSort_withCount(int* arr, int n, ll& count_compare);



bool isFileExists(const string& filename);
bool isNumber(const string& str);
int* readFile(string inputFile, int& n);
void writeFile(int* a, int n, string outputFile);
void Compare(int* a, int n, string algorithm, ll& count_compare);
void Time(int* a, int n, string algorithm, double& time);
void optionSort(int* a, int n, string algorithm, string outputParam, ll& count_compare, double& time);



#endif
