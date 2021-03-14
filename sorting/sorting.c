#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "sorting.h"

void BubbleSort(int arr[], int n) {
	int i, j, k;
	int temp;
	for (i = 0; i < n - 1; i++) {
		printf("\n\n-----------%d회차------------\n",i);
		for (k = 0; k < n; k++) {
			Sleep(300);
			printf("%d  ", arr[k]);
		}
		printf("\n");
		for (j = 0;j < n - 1;j++) {
			printf("\n");
			if (arr[j] > arr[i+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] = temp;

				for (k = 0; k < n; k++) {
					Sleep(300);
					printf("%d  ", arr[k]);
				}
			}
		}
		printf("\n\n");
		Sleep(1500);
	}
}

void SelectionSort(int arr[], int n) {
	int i, j, k;
	int maxIdx;
	int temp;
	for (i = 0;i < n - 1;i++) {
		printf("\n\n-----------%d회차------------\n", i);
		for (k = 0; k < n; k++) {
			Sleep(300);
			printf("%d  ", arr[k]);
		}
		maxIdx = 1;
		for (j = i + 1;j < n;j++) {
			if (arr[j] < arr[maxIdx])
				maxIdx = j;
		}
		temp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = temp;
	}
}
