#include <stdio.h>
#include <stdlib.h>

/**
   can process array less than 2^24 elements.
   OR
   allow a little errorness, store average of [i...N] instead of sum.
 */
int *preProcess(char array[], int N){
	int *p = (int *)malloc(sizeof(int) * (N+1));
	int i = 0; 
	p[N] = 0;
	for (i = N - 1; i >= 0; i--){
		p[i] = p[i+1] + array[i];
	}
	return p;
}
int findAverage(char array[], int N, int i, int j, int *hpa){
	if (i > j || i >= N || j >= N || i < 0 || j < 0)
		return -1;
	if (i == j)
		return 0;
	return (hpa[i] - hpa[j])/(j - i);
}
int findMiddle(char array[], int N, int i, int j){
	if (i > j || i >= N || j >= N || i < 0 || j < 0)
		return -1;
	if (i == j)
		return array[i];
	return (array[i] + array[j])/2;
}
int main(int argc, char **argv){
	char array[] = "asdfasdfasdfasdf";
	int *p = preProcess(array, 16);
	printf("find average 2 to 9: %d\n", findAverage(array, 16, 2, 9, p));
	printf("find middle 2 to 9: %d\n", findMiddle(array, 16, 2, 9));
	return 1;
}