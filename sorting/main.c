#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "sorting.h"
int main(void) {
	int arr[4] = {3,1,4,2};
	//BubbleSort(arr,sizeof(arr)/sizeof(int));
	SelectionSort(arr, sizeof(arr) / sizeof(int));
	return 0;
}
