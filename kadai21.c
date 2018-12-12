// M個の商品が与えられているとき、以下の考え方に基づき価格が低い商品群と高い商品群に分けて、価格の高い商品群を選択したい。

// ・どの選択される商品の価格も、どの選択されない商品の価格より高い。
// ・商品の選択数Nは、Nmin個以上、Nmax個以下とする。Nはこの範囲内でギャップを最大とするものでなくてはならない。ギャップとは、選択される商品の最低価格と、選択されない商品の最高価格の差である。
// ・同じギャップになるNが複数あるときは、その中でNが最大になるように選ぶ。

// 入力: 1行目にM Nmin Nmax、2行目にM個の商品価格 P1 P2 … PM
// 出力: 選択される商品数
// 制約: 0 < Nmin < Nmax < M <= 200, 0 <= Pi <= 10000 (ただし 1 <= i <= M), 全てのPiは異なる値を持つ。
// 参考: ICPC Domestic

// 入力例:
// 5 2 4
// 90 100 82 65 70

// 出力例:
// 3

#include <stdio.h>
#define SIZE 200

void swap(int *x, int *y) {
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main(void) {

  int M, N;
  int Nmin, Nmax;
  int P[SIZE];
  int i, j;
  int gap = 0;

  scanf("%d %d %d", &M, &Nmin, &Nmax);

  for (i = 0; i < M; i++) {
    scanf("%d", &P[i]);
  }

  for (i = 1; i < M; i++) {
    j = i;

    while ((j >= 1) && (P[j-1] < P[j])) {
      swap(&P[j-1], &P[j]);
      j--;
    }
  }

  for (i = Nmin; i <= Nmax; i++) {
    if ((P[i-1] - P[i]) > gap) {
      gap = P[i-1] - P[i];
      N = i;
    }
  }

  printf("%d\n", N);

  return 0;
}
