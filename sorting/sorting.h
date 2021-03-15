#pragma once
#ifndef _sorting_h_
#define _sorting_h_

void BubbleSort(int arr[], int n);
void SelectionSort(int arr[], int n);
void InserSort(int arr[], int n);

void MergeSort(int arr[], int left, int right);
void MergeTwoArea(int arr[], int left, int mid, int right);

void Swap(int arr[], int idx1, int idx2);
int Partition(int arr[], int left, int right);
void QuickSort(int arr[], int left, int right);
#endif