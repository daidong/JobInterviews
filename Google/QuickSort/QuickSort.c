#include <stdio.h>

/**
   In this program, we implement an in-place quicksort algorithm.
 */

static int inputs[16] = {15, 3, 2, 12, 14, 19, 20, 1, 2, 1, 31, 30, 29, 14, 13, 72};

int pivotPartition(int array[], int s, int e){
  int pivot = array[s];
  int mid = s;
  int largeS = s;
  int largeE = s;
  int curr = s + 1;

  for (curr; curr < e; curr++){
    if (array[curr] > pivot){
      largeE = curr;
    } else {
      int tmp = array[curr];
      int j = curr;
      for (j; j > largeS; j--)
	array[j] = array[j-1];
      array[largeS] = tmp;
      largeS++;
      mid++;
    }
  }

  return mid;
}

int QuickSort(int array[], int s, int e){
  if (e - s == 1)
    return 1;
  if (s == e)
    return 0;

  int mid = pivotPartition(array, s, e);
  return QuickSort(array, s, mid) + QuickSort(array, mid + 1, e) + 1;
}

int main(int argc, char **argv){
  int sortedElements = QuickSort(inputs, 0, 16);
  printf("Elements: %d\n", sortedElements);
  int i = 0;
  for (i = 0; i < sortedElements; i++){
    printf("%d ", inputs[i]);
  }
  printf("\n");
  return 1;
}
