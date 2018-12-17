// 与えられた根付き二分木の各節点について、以下の情報を出力するプログラムを作成しなさい。与えられる二分木はn個の節点を持ち、それぞれ0からn-1の番号が割り当てられているものとする。
// 節点番号
// 親
// 兄弟
// 子の数
// 深さ
// 高さ
// 入力: 1行目に接点の個数N、2行目以降にN個の以下の接点情報
// 節点番号 左の子の節点番号, 右の子の節点番号

// 出力: 接点番号の昇順に以下を出力して改行。ただし親や兄弟が無い場合の接点番号は-1とする。
// 接点番号 親の接点番号 兄弟の接点番号 子の数 深さ 高さ

// 制約: 1 <= n <= 25
// 参考: ALDS1_7_B 二分木

// 入力例:
// 9
// 0 1 4
// 1 2 3
// 2 -1 -1
// 3 -1 -1
// 4 5 8
// 5 6 7
// 6 -1 -1
// 7 -1 -1
// 8 -1 -1

// 出力例:
// 0 -1 -1 2 0 3
// 1 0 4 2 1 1
// 2 1 3 0 2 0
// 3 1 2 0 2 0
// 4 0 1 2 1 2
// 5 4 8 2 2 1
// 6 5 7 0 3 0
// 7 5 6 0 3 0
// 8 4 5 0 2 0

#include <stdio.h>
#include <stdlib.h>

typedef struct binarytree {
  int number;
  int parent_number;
  int brother_number;
  int child;
  int child_number[2];
  int depth;
} Node;

int max(int x, int y) {
  if (x >= y) {
    return x;
  } else {
    return y;
  }
}

int calc_height(Node node[], int i, int height) {
  if (node[i].child == 0) {
    return 0;
  } else {
    return max(calc_height(node, node[i].child_number[0], height+1), calc_height(node, node[i].child_number[1], height+1)) + 1;
  }
}

int main(void) {

  int n;
  int i;
  Node *node;
  int number, left_number, right_number;

  scanf("%d", &n);
  node = (Node *)malloc(sizeof(Node) * n);

  node[0].parent_number = -1;
  node[0].brother_number = -1;
  node[0].depth = 0;

  for (i = 0; i < n; i++) {
    scanf("%d %d %d", &number, &left_number, &right_number);
    node[number].number = number;
    if (left_number != -1 && right_number != -1) {
      node[number].child = 2;
      node[number].child_number[0] = left_number;
      node[number].child_number[1] = right_number;

      node[left_number].number = left_number;
      node[left_number].parent_number = number;
      node[left_number].brother_number = right_number;
      node[left_number].depth = node[number].depth + 1;

      node[right_number].number = right_number;
      node[right_number].parent_number = number;
      node[right_number].brother_number = left_number;
      node[right_number].depth = node[number].depth + 1;
    } else {
      node[number].child = 0;
    }
  }

  for (i = 0; i < n; i++) {
    printf("%d %d %d %d %d %d\n", node[i].number, node[i].parent_number, node[i].brother_number, node[i].child, node[i].depth, calc_height(node, i, 0));
  }

  free(node);

  return 0;
}
