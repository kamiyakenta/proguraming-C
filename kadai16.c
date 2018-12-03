#include <stdio.h>

long factorial(int n) {
  if (n == 0 || n == 1) return 1;
  else return n * factorial(n-1);
}

int main(void) {

  int m, n;
  long ans;

  scanf("%d %d", &m, &n);

  ans = factorial(m-1) / (factorial(m-n) * factorial(n-1));

  printf("%ld\n", ans);

  return 0;
}
