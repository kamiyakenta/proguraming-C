// 区画で区切られた部屋がある．区画の色は青か黄 である．青の区画に立っている人が隣接する四つの区画のうちで青の区画に移動できるとき，到達できる区画の数を答えるプログラムを書きなさい．

// 入力: 複数のデータセットからなる．データセットは，WとHという二つの正の整数からなる行で始まる．WとHは部屋のx方向，y方向に区画がいくつ並ぶかを表す．WとHは20以下である．その後ろにH行続く．それぞれの行にはW個の文字が含まれている．それぞれの文字は次に示すように区画の状態を表す．
// ’.’ - 青の区画
// ’#’ - 黄の区画
// ’@’ - 青の区画上の人(一つのデータセットに1度だけ出現)
// 入力の終わりは0を二つ含む行で表される．

// 出力: 入力のデータセットごとに， 最初の位置から到達可能な区画数を1行で出力して改行しなさい(最初の区画も含む)．
#include <stdio.h>

#define N 21

char A[N][N];
int check[N][N];

void search(int s, int t) {
  // check whether s, t in array range
  if (s < 0 || s >= N || t < 0 || t >= N) {
    return;
  } else if (A[s][t] == '#') {
    // when A[s][t] = '#'
    return;
  } else if (check[s][t] == 1) {
    // when already checked
    return;
  } else {
    // when s, t in array range
    if (A[s][t] == '.' || A[s][t] == '@') {
      check[s][t] = 1;
      // check top
      search(s-1, t);
      // check right
      search(s, t+1);
      // check left
      search(s, t-1);
      // check bottom
      search(s+1, t);
    }
  }
}

int main(void) {

  int W, H;
  int i, j;
  int s, t;
  int count;

  while (1) {
    scanf("%d", &W);
    scanf("%d", &H);

    if (W == 0 && H == 0) break;

    count = 0;

    // initialize A '0'
    for (i = 0; i < H; i++) {
      scanf("%s", A[i]);
    }
    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
        check[i][j] = 0;
        if (i >= H || j >= W) A[i][j] = '0';
        if (A[i][j] == '@') {
          s = i;
          t = j;
        }
      }
    }
    search(s, t);

    // output
    for (i = 0; i < H; i++) {
      for (j = 0; j < W; j++) {
        if (check[i][j] == 1) count++;
      }
    }
    printf("%d\n", count);
  }

  return 0;
}
