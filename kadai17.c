// N問のアンケートに連続して回答する。各問には「はい」または「いいえ」で答える。このとき、M問以上連続して「はい」となる回答の仕方が何通りであるかを求めなさい。下記の出力例は、「はい、はい、はい」「はい、はい、いいえ」「いいえ、はい、はい」の3通りを意味している。

// 入力: N M
// 出力: 通りの数を出力して改行
// 制約: 0 <= M <=N <= 20

// 入力例:
// 3 2

// 出力例:
// 3


//二分探索木で考える
#include <stdio.h>

//levelは木の高さ、yesは現時点でのyesの個数、Nは問題数、Mは連続してでてほしいyesの数
int bst(int level, int yes, int N, int M) {

  if(yes == M) return 1 << (N - level);
  //1をN分左シフトしてからlevelで引く   pow(回答の種類, 問題数ー判定してないレベル)
  else if(level >= N) return 0;
  else return bst(level+1, yes+1, N, M) + bst(level+1, 0, N, M);

}

int main(void) {

  int N, M;
  int ans;
  scanf("%d %d", &N, &M);

  ans = bst(0, 0, N, M);

  printf("%d\n", ans);

  return 0;
}
