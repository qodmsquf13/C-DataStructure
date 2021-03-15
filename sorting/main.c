#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "sorting.h"
#include "UsefulHeap.h"
int PriComp(int n1, int n2) {
	return n2 - n1;
}
void HeapSort(int arr[], int n, PriorityComp pc) {
	Heap heap;
	int i;
	HeapInit(&heap, pc);

	for (i = 0; i < n; i++) {
		HInsert(&heap, arr[i]);
		printf("%d¸¦ Èü¿¡ ³Ö¾ú½À´Ï´Ù.\n", arr[i]);
	}

	for (i = 0;i < n;i++) {
		arr[i] = HDelete(&heap);
		printf("%d¸¦ Èü¿¡¼­ ²¨³Â½À´Ï´Ù.\n", arr[i]);
	}
}
int main(void) {
	int arr[8] = {8,2,3,7,1,5,4,6};
	//BubbleSort(arr,sizeof(arr)/sizeof(int));
	//SelectionSort(arr, sizeof(arr) / sizeof(int));
	//InserSort(arr, sizeof(arr) / sizeof(int));
	//HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);
	//MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	QuickSort(arr,0, sizeof(arr) / sizeof(int)-1);
	for (int k = 0; k < 7; k++) {
		Sleep(300);
		printf("%d  ", arr[k]);
	}
	return 0;
}
