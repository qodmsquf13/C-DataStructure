#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "sorting.h"
#include "UsefulHeap.h"

void BubbleSort(int arr[], int n) {
	int i, j, k;
	int temp;
	for (i = 0; i < n - 1; i++) {
		printf("\n\n-----------%dȸ��------------\n",i);
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
		
		printf("\n");
		maxIdx = i;
		for (j = i + 1;j < n;j++) {
			if (arr[j] < arr[maxIdx]){
				maxIdx = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = temp;

		printf("\n\n-----------%dȸ��------------\n", i);
		for (k = 0; k < n; k++) {
			Sleep(300);
			printf("%d  ", arr[k]);
		}
	}

}

void InserSort(int arr[],int n) {
	int i, j, k;
	int insData;

	for (i = 1;i < n;i++) {
		insData = arr[i];
		printf("\n%d�� ���Ĵ������ �����մϴ�.\n", arr[i]);
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > insData)
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = insData;
		Sleep(500);
		printf("\n\n-----------%dȸ��------------\n", i - 1);
		for (k = 0; k < n; k++) {
			Sleep(300);
			printf("%d  ", arr[k]);
		}
	}
}

void MergeTwoArea(int arr[], int left, int mid, int right) {
	int fIdx = left;
	int rIdx = mid + 1;
	int i;

	int* sortArr = (int*)malloc(sizeof(int) * (right + 1));
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right) {
		if (arr[fIdx] <= arr[rIdx]) {
			sortArr[sIdx] = arr[fIdx++];
			//���� �� �� ������ �����͸�
			//���Ͽ� �迭�� ����
		}
		else {
			sortArr[sIdx] = arr[rIdx++];
			//���� �� �� ������ �����͸�
			//���Ͽ� �迭�� ����
		}

		sIdx++;
	}

	if (fIdx > mid) {
		for (i = rIdx; i <= right; i++, sIdx++)
			sortArr[sIdx] = arr[i];
		//�迭�� �� �κ��� sortArr�� ��� �̵��Ǿ 
		//�迭 �޺κп� ���� �����͸� ��� sortArr�� �̵�
	}
	else {
		for (i = fIdx; i <= mid; i++, sIdx++)
			sortArr[sIdx] = arr[i];
		//�迭�� �� �κ��� sortArr�� ��� �̵��Ǿ 
		//�迭 �պκп� ���� �����͸� ��� sortArr�� �̵�
	}

	for (i = left; i <= right; i++) {
		arr[i] = sortArr[i];
		//���� ����� �ű��.
	}

	free(sortArr);
}

void MergeSort(int arr[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2; //�߰� ���� ���

		MergeSort(arr, left, mid); //�ѷ� ������ ������ ����
		MergeSort(arr, mid + 1, right); //�ѷ� ������ ������ ����

		MergeTwoArea(arr, left, mid, right); //����
	}
}

void Swap(int arr[], int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int arr[], int left, int right) {
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high) {
		if (arr[low] <= pivot && low <= right)
			low++;

		if (arr[high] > pivot && high >= left + 1)
			high--;

		if (low <= high)
			Swap(arr, low, high);
	}

	Swap(arr, left, high);

	return high;
}

void QuickSort(int arr[], int left, int right) {
	if (left <= right) {

		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}