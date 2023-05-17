#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
#include"stack.h"

void PrintArray(int* a, int n);
void InsertSort(int* a, int n);
void ShellSort(int* a, int n);
void SelectSort(int* a, int n);
void HeapSort(int* a, int n);
void BubbleSort(int* a, int n);
void QuickSort(int* a, int left,int right);
void MergeSort(int* a, int n);
int partion(int* a, int left, int right);
void QuickSortNonR(int* a, int left, int right);//¿ìÅÅµÄ·ÇµÝ¹é
void MergeSortNonR(int* a,int n);

