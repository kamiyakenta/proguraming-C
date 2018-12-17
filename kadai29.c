// 入力の最初の行に、節点の個数 n が与えられます。続く n 行目に、各節点の情報が以下の形式で１行に与えられます。

// id left right

// id は節点の番号、left は左の子の番号、right は右の子の番号を表します。子を持たない場合は left (right) は -1 で与えられます。

// 出力
// １行目に"Preorder"と出力し
// ２行目に先行順巡回を行った節点番号を順番に出力してください。
// ３行目に"Inorder"と出力し、
// ４行目に中間順巡回を行った節点番号を順番に出力してください。
// ５行目に"Postorder"と出力し、
// ６行目に後行順巡回を行った節点番号を順番に出力してください。

// 節点番号の前に１つの空白文字を出力してください。

// 制約
// 1≤n≤25
// 入力例
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
// 出力例
// Preorder
// 0 1 2 3 4 5 6 7 8
// Inorder
// 2 1 3 0 6 5 7 4 8
// Postorder
// 2 3 1 6 7 5 8 4 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  int left;
  int right;
  int is_root;// 1 or 0
} Node;

int get_root_id(int n, Node nodes[n]) { //rootを探す関数
  int i;
  for(i = 0; i < n; i++) {
    int l = nodes[i].left, r = nodes[i].right;
    if(l != -1) nodes[l].is_root = 0;
    if(r != -1) nodes[r].is_root = 0;
  }
  int root_id = -1;
  for(i = 0; i < n; i++) {
    if(nodes[i].is_root == 1) {
      root_id = i;
      break;
    }
  }
  return root_id;
}
void preorder(int root_id, int n, Node nodes[n]) {
  int l = nodes[root_id].left;
  int r = nodes[root_id].right;
  printf(" %d", root_id);
  if(l != -1) preorder(l, n, nodes);
  if(r != -1) preorder(r, n, nodes);
}
void inorder(int root_id, int n, Node nodes[n]) {
  int l = nodes[root_id].left;
  int r = nodes[root_id].right;
  if(l != -1) inorder(l, n, nodes);
  printf(" %d", root_id);
  if(r != -1) inorder(r, n, nodes);
}

void postorder(int root_id, int n, Node nodes[n]) {
  int l = nodes[root_id].left;
  int r = nodes[root_id].right;
  if(l != -1) postorder(l, n, nodes);
  if(r != -1) postorder(r, n, nodes);
  printf(" %d", root_id);
}

int main(){
  int n;
  scanf("%d", &n);
  Node nodes[n];
  int i;
  for(i = 0; i < n; i++) {
    int id;
    scanf("%d",  &id);
    scanf("%d %d", &nodes[id].left, &nodes[id].right);
    nodes[id].is_root = 1;
  }
  int root_id = get_root_id(n, nodes);

  printf("Preorder\n");
  preorder(root_id, n, nodes);
  printf("\n");

  printf("Inorder\n");
  inorder(root_id, n, nodes);
  printf("\n");

  printf("Postorder\n");
  postorder(root_id, n, nodes);
  printf("\n");
  return 0;
}

