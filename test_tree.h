#include <stdlib.h>
#include <stdbool.h>
#define _TREE_H_

// 節の定義
typedef struct node {
  double item;
  struct node *left;
  struct node *right;
} Node;

// 木の定義
typedef struct {
  Node *root;
} Tree;

// 関数宣言
Tree *make_tree(void);
void destroy_tree(Tree *tree);
bool is_empty_tree(Tree *tree);
bool search_tree(double x, Tree *tree);
double search_min_tree(Tree *tree, bool *err);
double search_max_tree(Tree *tree, bool *err);
void insert_tree(double x, Tree *tree);
void delete_tree(double x, Tree *tree);
void delete_min_tree(Tree *tree);
void delete_max_tree(Tree *tree);
void foreach_tree(void (*func)(double), Tree *tree);
