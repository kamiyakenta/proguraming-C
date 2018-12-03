// n個の整数を含む数列Sと、q個の異なる整数を含む数列Tが与えられるとき、
// Tに含まれる整数の中でSに「含まれない」ものを空白区切りで列挙し（c個の整数を含む数列Vとする）、
// さらに個数cを出力しなさい。

// 入力: 1行目にn、2行目にSを表すn個の空白区切りの整数、3行目にq、4行目にTを表すq個の空白区切りの整数、および改行
// 出力: Vを空白区切りの数列として出力し（要素数0の場合は空行）、改行して、cを出力し、改行して終わること。

#include <stdio.h>
#include <stdlib.h>
#define N 100

int asc(const void *a, const void *b){
  return *(int *)a - *(int *)b;
}

int main(void){
  int n, q;
  int i, j;
  int flag = 0;
  int count =0;
  int k = 0;
  int a[N];

  scanf("%d", &n);
  int S[n];
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }//探索される方

  scanf("%d", &q);
  int T[q];
  for(i = 0; i < q; i++){
    scanf("%d", &T[i]);
  }//一つずつ探索する方



  //二分探索のために探索される方の配列S[]をソートする
  qsort(S, n, sizeof(int), asc);
  //配列, 要素数, 配列要素のサイズ, 比較関数(main外で宣言している)


  //二分探索
  int left;
  int right;
  int mid;

  for(i = 0; i < q; i++){
    left = 0;
    right = n-1;
    while(left <= right){
      mid = (left + right) / 2;
      if(S[mid] == T[i]){
        flag = 0;
        break;
      }else if(S[mid] < T[i]){
        left = mid + 1;
        flag = 1;
      }else{
        right = mid - 1;
        flag = 1;
      }
    }
    if(flag == 1){
      a[count] = T[i];
      count++;
      flag = 0;
    }
  }

  //出力
  for(k=0; k<count; k++){
    if(k != count-1){
      printf("%d ", a[k]);
    }else{
      printf("%d\n", a[k]);
    }
  }

  if (count == 0){
      printf("\n%d\n", count);
  }else{
      printf("%d\n", count);
  }

  return 0;
}
