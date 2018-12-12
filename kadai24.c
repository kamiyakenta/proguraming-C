// 整数の配列A（ただし要素数n）が与えられたとき、要素の最小値を線形探索「ではなく」、分割統治法により求めなさい。

// 入力: 1行目にn、続いて配列Aの要素が空白区切りによりn個連続
// 出力: 再帰的に部分列の最小値を求めるたびにその値を出力して改行すること。

// 入力例:
// 4
// 3 5 6 2

// 出力例:
// 3
// 5
// 3
// 6
// 2
// 2
// 2

#include <stdio.h>

int min(int a[], int left, int right) {
  int s1,s2,ans;
  if(right == left) {
    ans = a[left];
  } else {
    s1 = min(a, left, (left + right)/2);
    s2 = min(a, (left + right)/2 + 1, right);
    if(s1 > s2){
      ans = s2;
    }else{
      ans = s1;
    }
  }
  printf("%d\n", ans);
  return ans;
}

int main(void) {
  int ans;
  int i;
  int n;
  scanf("%d", &n);
  int a[n];
  for(i = 0; i < n; i++){
    scanf("%d",&a[i]);
  }
  ans = min(a, 0 ,n-1);
  return 0;
}
