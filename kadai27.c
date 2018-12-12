// 与えられた根付き木の各節点について、以下の情報を出力するプログラムを作成しなさい。
// 節点番号
// 親の節点番号
// 深さ
// 入力: 1行目に接点の個数N、2行目以降にN個の以下の接点情報
// 節点番号 次数k 1番目の子の節点番号, … k番目の子の節点番号

// 出力: 接点番号の昇順に以下を出力して改行。ただし親が無い場合の「親の接点番号」は-1とする。
// 接点番号 親の接点番号 深さ

// 制約: 1 <= n <= 100,000, 接点の深さは20を超えない、任意の2つの接点間には必ず経路がある
// 参考: ALDS1_7_A 根付き木

// 入力例:
// 4
// 1 3 3 2 0
// 0 0
// 3 0
// 2 0

// 出力例:
// 0 1 1
// 1 -1 0
// 2 1 1
// 3 1 1

#include <stdio.h>
#include <stdlib.h>

typedef struct data {
  int number;
  int k;
  int p_n; //親の数
  int depth;
  int *child;
} Node;

void calc_depth(Node node[], int i) {
  int j;
  for (j = 0; j < node[i].k; j++) {
    node[node[i].child[j]].depth = node[i].depth + 1;
    calc_depth(node, node[node[i].child[j]].number);
  }
}

int main(void) {

  int n;
  int i, j;
  int number;
  int k;
  int c_n; //子供の数
  Node *node;

  scanf("%d", &n);

  node = (Node *)malloc(sizeof(Node) * n);

  for (i = 0; i < n; i++) {
    scanf("%d", &number);
    scanf("%d", &k);
    node[number].number = number;
    node[number].k = k;
    node[number].p_n = -1;
    node[number].child = (int *)malloc(sizeof(int) * k);

    for (j = 0; j < k; j++) {
      scanf("%d", &c_n);
      node[number].child[j] = c_n;
    }
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < node[i].k; j++) {
      node[node[i].child[j]].p_n = node[i].number;
    }
  }

  for (i = 0; i < n; i++){
    if (node[i].p_n == -1){
      calc_depth(node, i);
    }
  }

  for (i = 0; i < n; i++) {
    printf("%d %d %d\n", node[i].number, node[i].p_n, node[i].depth);
  }
  return 0;
}
