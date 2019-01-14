#include <stdio.h>
#define N 101

int main(void) {

  int i, j;
  int n;
  int A[N][N] = {0};
  int col, row;
  int count;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d %d", &col, &count);
    for (j = 0; j < count; j++) {
      scanf("%d", &row);
      A[col][row] = 1;
    }
  }

  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (j != n) printf("%d ", A[i][j]);
      else printf("%d\n", A[i][j]);
    }
  }

  return 0;
}