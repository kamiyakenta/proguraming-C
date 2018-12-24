#include <stdio.h>
#define N 200000

long aux[N];
int count = 0;

void merge(long A[], int left, int medium, int right){
	int i, j, k;
	for (i = left; i <= medium; i++) aux[i] = A[i];
	for (j = medium; j < right; j++) {
		aux[right+medium-j] = A[j+1];
		for (i = left; i <= medium; i++) {
		 	if (aux[i] > aux[right+medium-j]) count++;
		}
	}
	i = left;
	j = right;
	for (k = left; k <= right; k++) {
		if (aux[i] < aux[j]) {
			A[k] = aux[i++];
		} else {
			A[k] = aux[j--];
		}
	}
	printf("%d\n", count);
}

void mergesort(long A[], int left, int right) {
	int medium = (right+left-1) / 2;
	if (right <= left) return;
	mergesort(A,left,medium);
	mergesort(A,medium+1,right);
	merge(A,left,medium,right);
}

int main(void) {
	int n;
	int i, j;
	long A[N];
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%ld", &A[i]);
	
  mergesort(A,0,n-1);

	return 0;
}
