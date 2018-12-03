// M個のプログラミング課題をN人で分担して解こうとしている。ただし各人は必ず1題は解かなければならない。
// このとき分担の仕方の数を、再帰を用いて求めなさい。

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
