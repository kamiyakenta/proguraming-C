#include "test_tree.h"

// 節の生成
static Node *make_node(double x)
{
  Node *node = malloc(sizeof(Node));
  if (node != NULL) {
    node->item = x;
    node->left = NULL;
    node->right = NULL;
  }
  return node;
}

// 節の廃棄
static void destroy_node(Node *node)
{
  if (node != NULL) {
    destroy_node(node->left);
    destroy_node(node->right);
    free(node);
  }
}

// データの探索
static bool search_node(double x, Node *node)
{
  while (node != NULL) {
    if (node->item == x)
      return true;
    else if (x < node->item)
      node = node->left;
    else
      node = node->right;
  }
  return false;
}

// データの挿入
static Node *insert_node(double x, Node *node)
{
  if (node == NULL)
    return make_node(x);
  else if (x < node->item)
    node->left = insert_node(x, node->left);
  else if (x > node->item)
    node->right = insert_node(x, node->right);
  return node;
}

// 最小値の探索
static double search_min(Node *node)
{
  while (node->left != NULL) node = node->left;
  return node->item;
}

// 最大値の探索
static double search_max(Node *node)
{
  while (node->right != NULL) node = node->right;
  return node->item;
}

// 最小値の削除
static Node *delete_min(Node *node)
{
  if (node->left == NULL) {
    Node *temp = node->right;
    free(node);
    return temp;
  }
  node->left = delete_min(node->left);
  return node;
}

// 最大値の削除
static Node *delete_max(Node *node)
{
  if (node->right == NULL) {
    Node *temp = node->left;
    free(node);
    return temp;
  }
  node->right = delete_max(node->right);
  return node;
}

// データの削除
static Node *delete_node(double x, Node *node)
{
  if (node == NULL) return NULL;
  if (x == node->item) {
    if (node->left == NULL) {
      Node *temp = node->right;
      free(node);
      return temp;
    }
    if (node->right == NULL) {
      Node *temp = node->left;
      free(node);
      return temp;
    }
    node->item = search_min(node->right);
    node->right = delete_min(node->right);
  } else if (x < node->item)
    node->left = delete_node(x, node->left);
  else
    node->right = delete_node(x, node->right);
  return node;
}

// 巡回
static void foreach_node(void (*func)(double), Node *node)
{
  if (node != NULL) {
    foreach_node(func, node->left);
    func(node->item);
    foreach_node(func, node->right);
  }
}

//
// 公開する関数
//

// 木の生成
Tree *make_tree(void)
{
  Tree *tree = malloc(sizeof(Tree));
  if (tree != NULL) {
    tree->root = NULL;
  }
  return tree;
}

// 木の廃棄
void destroy_tree(Tree *tree)
{
  destroy_node(tree->root);
  free(tree);
}

// 空の木か
bool is_empty_tree(Tree *tree)
{
  return tree->root == NULL;
}

// データの探索
bool search_tree(double x, Tree *tree)
{
  return search_node(x, tree->root);
}

// 最小値を求める
double search_min_tree(Tree *tree, bool *err)
{
  if (is_empty_tree(tree)) {
    *err = false;
    return 0;
  }
  *err = true;
  return search_min(tree->root);
}

// 最大値を求める
double search_max_tree(Tree *tree, bool *err)
{
  if (is_empty_tree(tree)) {
    *err = false;
    return 0;
  }
  *err = true;
  return search_max(tree->root);
}

// データの挿入
void insert_tree(double x, Tree *tree)
{
  tree->root = insert_node(x, tree->root);
}

// データの削除
void delete_tree(double x, Tree *tree)
{
  tree->root = delete_node(x, tree->root);
}

// 最小値を削除
void delete_min_tree(Tree *tree)
{
  if (!is_empty_tree(tree))
    tree->root = delete_min(tree->root);
}

// 最大値を削除
void delete_max_tree(Tree *tree)
{
  if (!is_empty_tree(tree))
    tree->root = delete_max(tree->root);
}

// 巡回
void foreach_tree(void (*func)(double), Tree *tree)
{
  foreach_node(func, tree->root);
}
