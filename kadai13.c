// 区画で区切られた部屋がある．区画の色は青か黄 である．青の区画に立っている人が隣接する四つの区画のうちで青の区画に移動できるとき，到達できる区画の数を答えるプログラムを書きなさい．

// 入力: 複数のデータセットからなる．データセットは，WとHという二つの正の整数からなる行で始まる．WとHは部屋のx方向，y方向に区画がいくつ並ぶかを表す．WとHは20以下である．その後ろにH行続く．それぞれの行にはW個の文字が含まれている．それぞれの文字は次に示すように区画の状態を表す．
// ’.’ - 青の区画
// ’#’ - 黄の区画
// ’@’ - 青の区画上の人(一つのデータセットに1度だけ出現)
// 入力の終わりは0を二つ含む行で表される．

// 出力: 入力のデータセットごとに， 最初の位置から到達可能な区画数を1行で出力して改行しなさい(最初の区画も含む)．

#include <stdio.h>

#define N 21 //外枠も考える

char Map[N][N];
int flag[N][N];

void search(int x, int y) {
  if (x < 0 || x >= N || y < 0 || y >= N) return;
  else if(Map[x][y] == '#') return;
  else if(flag[x][y] == 1) return;
  else {
    if (Map[x][y] == '.' || Map[x][y] == '@') {
      flag[x][y] = 1;
      //四方向で探す
      search(x-1, y);
      search(x, y+1);
      search(x, y-1);
      search(x+1, y);
    }
  }
}

int main(void) {

  int W, H;
  int i, j;
  int x, y; //現在地
  int count;

  while (1) {
    scanf("%d", &W);
    scanf("%d", &H);
    count = 0;

    if (W == 0 || H == 0) break;

    //地図の入力
    for (i = 0; i < H; i++) {
      scanf("%s", Map[i]);
    }

    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
        flag[i][j] = 0;  //通ってないところは０
        if (i >= H || j >= W) Map[i][j] = '0';
        if (Map[i][j] == '@') { //スタート地点
          x = i;
          y = j;
        }
      }
    }
    search(x, y);

    // output
    for (i = 0; i < H; i++) {
      for (j = 0; j < W; j++) {
        if (flag[i][j] == 1) count++;
      }
    }
    printf("%d\n", count);
  }

  return 0;
}
