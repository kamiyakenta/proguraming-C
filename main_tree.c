#include <stdio.h>
#include <time.h>
#include "test_tree.h"

// データの表示
void print_item(double x)
{
  printf("%.3f ", x);
}

void print_tree(Tree *tree)
{
  foreach_tree(print_item, tree);
  printf("\n");
}

// 木の高さ
int height_node(Node *node)
{
  if (node == NULL) return 0;
  int a = height_node(node->left);
  int b = height_node(node->right);
  return 1 + (a > b ? a : b);
}

int height_tree(Tree *tree)
{
  return height_node(tree->root);
}

// シャッフル
void shuffle(double *buff, int size)
{
  for (int i = size - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    double tmp = buff[i];
    buff[i] = buff[j];
    buff[j] = tmp;
  }
}

#define N 10

void test1(void)
{
  double buff[N] = {5,6,4,7,3,8,2,9,1,0};
  Tree *tree = make_tree();
  for (int i = 0; i < N; i++) {
    insert_tree(buff[i], tree);
    print_tree(tree);
  }
  for (int i = -1; i < N + 1; i++)
    printf("%d\n", search_tree(i, tree));
  for (int i = 0; i < N; i++) {
    delete_tree(buff[i], tree);
    print_tree(tree);
  }
  destroy_tree(tree);
}

#define M 2000000

double buff[M];

void test2(void)
{
  for (int n = 250000; n <= M; n *= 2) {
    Tree *tree = make_tree();
    for (int i = 0; i < n; i++) buff[i] = rand();
    printf("----- %d -----\n", n);
    clock_t s = clock();
    for (int i = 0; i < n; i++)
      insert_tree(buff[i], tree);
    printf("挿入時間 %.3f\n", (double)(clock() - s) / CLOCKS_PER_SEC);
    printf("高さ %d\n", height_tree(tree));
    s = clock();
    for (int i = 0; i < n; i++)
      if (!search_tree(buff[i], tree)) fprintf(stderr, "search error\n");
    printf("探索時間 %.3f\n", (double)(clock() - s) / CLOCKS_PER_SEC);
    s = clock();
    for (int i = 0; i < n; i++)
      delete_tree(buff[i], tree);
    printf("削除時間 %.3f\n", (double)(clock() - s) / CLOCKS_PER_SEC);
    destroy_tree(tree);
  }
}

int main(void)
{
  test1();
  test2();
  return 0;
}
