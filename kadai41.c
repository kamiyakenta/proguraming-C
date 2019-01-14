#include <stdio.h>
#include <stdlib.h>
#define N 101

int main(void) {

  int n;
  int A[N][N];
  int count[N];
  int i, j;
  int sum = 0;

  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      scanf("%d", &A[i][j]);
      sum += A[i][j];
    }
    count[i] = sum;
    sum = 0;
  }

  for (i = 1; i <= n; i++) {
    printf("%d %d", i, count[i]);
    for(j = 1; j <= n; j++) {
      if (A[i][j] == 1) {
        printf(" %d", j);
      }
    }
    printf("\n");
  }

  return 0;
}