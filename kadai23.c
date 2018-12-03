// N個の整数を含む数列Aをバケツ（計数）ソートで降順にソートしなさい。また、各整数の個数も出力すること。例えば下記の出力例では1行目に、0が1個、1が1個、2が2個、・・・、5が1個と出力したうえで、2行目にソートした結果を出力している。

// 入力: 1行目にN、2行目にAを表すN個の空白区切りの数列
// 出力: 1行目に各整数の個数（ただしAに含まれる最大値まで）、2行目に降順にバケツ（計数）ソートした結果の空白区切りの数列を出力し改行

#include <stdio.h>

int Max(int a[], int n){
  int i;
  int max = 0;
  for(i = 0; i < n; i++){
    if(max < a[i]){
      max = a[i];
    }
  }
  return max;
}

void bucket_sort(int a[], int n){
  int i, j;
  int max;
  max = Max(a, n);
  int count[max+1];
  int buckets[max+1];
  int k = 0;

  for(i = 0; i < max+1; i++){
    buckets[i] = 0;
    count[i] = 0;
  }

  for(i = 0; i < n; i++){
    buckets[a[i]] = a[i];
    count[a[i]]++;
  }

  for (i = 0; i < max+1; i++){
    if(i==max){
      printf("%d\n", count[i]);
    }else{
      printf("%d ", count[i]);
    }
  }

  for(i = max; i >= 0; i--){
    for(j = 0; j < count[i]; j++){
      a[k] = i;
      k++;
    }
  }
}

int main(void){
  int i, n;
  scanf("%d", &n);
  int a[n];

  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  bucket_sort(a, n);

  for (i = 0; i < n; i++)
    if(i == n-1) printf("%d", a[i]);
    else printf("%d ", a[i]);
  printf("\n");
  return 0;
}
