#include <stdio.h>

/**
  In this file, we will write the recursive version of QuickSort and
the loop version. Also there is an implementation on the immutable 
array.
  */
#define N 5

int partition(int *array, int len, int start, int end){
	if (array == NULL || len < 0 || start > end || start < 0 || end > len)
		return -1;
	
	int needsSwap = start - 1;
	int index = start;
	int pivlot = array[end-1];
	int tmp = 0;
	
	for (index = start; index < end; index++){
		if (array[index] < pivlot){
			needsSwap ++;
			if (needsSwap != index){
				tmp = array[index];
				array[index] = array[needsSwap];
				array[needsSwap] = tmp;
			}
		}
	}
	needsSwap++;
	array[end - 1] = array[needsSwap];
	array[needsSwap] = pivlot;
	return needsSwap;
}

void quicksortCore(int *array, int start, int end){
	if (start == end)
		return;
		
	int mid = partition(array, N, start, end);
	if (mid > start)
		quicksortCore(array, start, mid);
	if (mid < end)
		quicksortCore(array, mid+1, end);
		
}
void quicksort(int *array, int len){
	if (array == NULL || len == 0)
		return;
	quicksortCore(array, 0, len);
}

int *quicksort2(int *array, int len){
	return NULL;
}
void quicksortLoop(int *array, int len){
	
}
void printArray(int *p, int len){
	int i = 0;
	for (i = 0; i < len; i++){
		printf("%d ", p[i]);
	}
	printf("\n");
}
int main(int argc, char **argv){
	int unsort[] = {23,2345,5645,234,112};
	printArray(unsort, N);
	
	quicksort(unsort, N);
	printArray(unsort, N);
	/*
	int immutable[] = {};
	int *sorted = quicksort2(immutable, N);
	printArray(sorted, N);
	
	int unsort2[] = {};
	quicksortLoop(unsort, N);
	printArray(unsort, N);
	*/
	return 1;
}