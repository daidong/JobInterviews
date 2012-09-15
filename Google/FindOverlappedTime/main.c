#include <stdio.h>

long findMax(long a[], int size){
  long max = (1L<<63) + 1;
  printf("Max: %ld\n", max);
  int j = 0;
  for (j = 0; j < size; j++){
    if (a[j] >= max)
      max = a[j];
  }
  return max;
}

long findMin(long a[], int size){
  long min = ~(1L<<63);
  printf("Min: %ld\n", min);
  int j = 0;
  for (j = 0; j < size; j++){
    if (a[j] <= min)
      min = a[j];
  }
  return min;
}

int main(){
  long ts1[10];
  long ts2[10];
  
  FILE* fp = NULL;
  if ((fp = fopen("times.txt", "r")) == NULL){
    printf("Not Opened");
    return 0;
  }

  int i = 0;
  while (fscanf(fp, "%ld %ld\n", &ts1[i], &ts2[i]) != EOF){
    i++;
  }

  long s = findMax(ts1, i);
  long e = findMin(ts2, i);

  if (s <= e)
    printf("Overlapped Time is: [%ld %ld]\n" , s, e);
  else
    printf("No Overlapped Time\n");
  
  return 1;
}
