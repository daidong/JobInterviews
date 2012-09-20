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
double *preProcess2(char array[], int N){
	double *p = (double *)malloc(sizeof(double) * (N+1));
	int i = 0; 
	p[N] = 0.0;
	for (i = N - 1; i >= 0; i--){
		p[i] = (p[i+1] * (N - i - 1) + array[i])/(N - i);
	}
	return p;
}
int findAverage2(char array[], int N, int i, int j, double *hpa){
	if (i > j || i >= N || j >= N || i < 0 || j < 0)
		return -1;
	if (i == j)
		return 0;
	return (hpa[i] * (N - i) - hpa[j] * (N - j)) / (j - i);
}
int findMiddleCore(char *a, int s, int e, int find){
	int index = e;
	
	int small = s - 1;
	for (index = s; index < e; index++){
		if (a[index] < a[e]){
			small++;
			if (small != index){
				char tmp = a[index];
				a[index] = a[small];
				a[small] = tmp;
			}
		}
	}
	small++;	
}

int findMiddle(char array[], int N, int i, int j){
	if (i > j || i >= N || j >= N || i < 0 || j < 0)
		return -1;
	if (i == j)
		return array[i];
	return findMiddleCore(array, i, j, (j - i + 1)/2 );
}
int main(int argc, char **argv){
	char array[] = "asdfasdfasdfasdf";
	int *p = preProcess(array, 16);
	double *pd = preProcess2(array, 16);
	printf("find average 2 to 9: %d\n", findAverage(array, 16, 2, 9, p));
	printf("find average 2 to 9: %d\n", findAverage2(array, 16, 2, 9, pd));
	printf("find middle 2 to 9: %d\n", findMiddle(array, 16, 2, 9));
	return 1;
}