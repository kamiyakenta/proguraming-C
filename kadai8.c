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
