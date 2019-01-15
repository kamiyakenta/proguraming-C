#include <stdio.h>
#define MAX 21

long memo[MAX];

long recursion(int n);

int main(void) {

  int M, N;
  int i;

  scanf("%d %d", &M, &N);

  for (i = 0; i < MAX; i++) memo[i] = 0;

  printf("%ld\n", recursion(M+N-1) / (recursion(M) * recursion(N-1)));

  return 0;
}

long recursion(int n) {
  if (n == 0 || n == 1) return 1;
  if (memo[n] != 0) return memo[n];
  return memo[n] = n * recursion(n-1);
}
