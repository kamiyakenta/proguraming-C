#include <stdio.h>
#define N 100

int main(void){
  // int n, q;
  // int i, j;
  // int flag = 0;
  // int count =0;
  // int k = 0;
  // int a[N];

  //節を定義
  typedef struct node {
    int item;
    struct node *left;
    struct node *right;
  } Node;

  //節の生成
  static Node *make_node(int x){
    Node *node = malloc(sizeof(Node));
    if (node != NULL) {
      node->item = x;
      node->left = NULL;
      node->right = NULL;
    }
    return node;
  }

  //節の探索
  static bool search_node(int x, Node *node){
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

  //節の挿入
  static Node *insert_node(int x, Node *node){
    if (node == NULL)
      return make_node(x);
    else if (x < node->item)
      node->left = insert_node(x, node->left);
    else if (x > node->item)
      node->right = insert_node(x, node->right);
    return node;
  }

  // scanf("%d", &n);
  // int S[n];
  // for(i = 0; i < n; i++){
  //   scanf("%d", &S[i]);
  // }

  // scanf("%d", &q);
  // int T[q];
  // for(i = 0; i < q; i++){
  //   scanf("%d", &T[i]);
  // }

  // //入力完了

  // for(i = 0; i < q; i++){
  //   for(j = 0; j < n; j++){
  //     if(T[i] == S[j]){
  //       flag = 0;
  //       break;
  //     }else{
  //       flag = 1;
  //     }
  //   }
  //   if(flag == 1){
  //     a[count] = T[i];
  //     count++;
  //     flag = 0;
  //   }
  // }
  // for(k=0; k<count; k++){
  //   if(k != count-1){
  //     printf("%d ", a[k]);
  //   }else{
  //     printf("%d\n", a[k]);
  //   }
  // }
  // if (count == 0){
  //     printf("\n%d\n", count);
  // }else{
  //     printf("%d\n", count);
  // }
  return 0;
}
