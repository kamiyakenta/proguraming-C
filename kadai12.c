// 多くの商品の中で、価格の差が最も小さい対を選び、その差の絶対値を出力しなさい。

// 入力: 複数のデータセットからなる． 各データセットは次の形式で表される．
// n
// a1 a2 … an
// データセットは 2 行からなる． 1行目には商品数 n が与えられる． n は整数であり，2 ≤ n ≤ 1000 が成り立つ． 2 行目には n 個の商品価格が与えられる．この値は整数であり，0 以上 1,000,000 以下である．入力の終わりは，1 個のゼロだけからなる行で表される． 全データセットの n の合計は 50,000 を超えない．

// 出力: 各データセットについて，価格の差が最小の 2 個の商品を選び，その差（の絶対値）を 1 行に出力して改行しなさい．

#include <stdio.h>
#include <stdlib.h>

void mindif(int a[], int n){
  int i, j;
  int dif;
  int min;
  min = abs(a[0]-a[1]);
  for(i = 0; i < n-1; i++){
    for(j = i+1; j < n; j++){
      dif = abs(a[i]-a[j]);
      if( min > dif ){
        min = dif;
      }
    }
  }
  printf("%d\n", min);
}


int main(void){
  int n;
  int i;

  while(1){
    scanf("%d", &n);
    if(n==0) break;
    int a[n];
    for(i=0; i<n; i++){
      scanf("%d", &a[i]);
    }
    mindif(a, n);
  }
  return 0;
}
