#include <stdio.h>
#define MAX_N 100

typedef struct Pro {
  char name[11];
  int time;
} Pro; //１セットにcharとintを入れたいので構造体を作る

Pro que[MAX_N];
Pro fin[MAX_N];
Pro tmp2;

int main() {
  int num; //プロセスの数
  int q; //クォンタムの値
  int i, j, k=0;
  int cnt;
  int time; //現時点の総時間
  int tmp;


  scanf("%d %d", &num, &q);

  for(i = 0; i < num; ++i) {
    scanf(" %s %d", que[i].name, &(que[i].time));
  }
  //全ての入力完了
  printf("\n");

  for(cnt = 0, time = 0; cnt < num; ) {

    if (q < que[0].time){
      tmp = q;  //クォンタムより大きかったらクォンタム分のみ
    }else{
      tmp = que[0].time;  //クォンタムより小さかったらそのプロセスのタイム
    }

    que[0].time -= tmp;
    time += tmp;

    //もうプロセス終了したら結果にいれる
    if(que[0].time == 0) {
      fin[k] = que[0];
      fin[k].time = time;
      k++;
      cnt++;
    }

    //キューの循環
    tmp2 = que[0];
    for (j = 1; j < num; j++){
      que[j-1] = que[j];
    }
    que[num-1] = tmp2;

    //毎度キューの中身を全て出力
    for(j = 0; j < num; j ++){
      if(que[j].time != 0){
        printf("%s %d ", que[j].name, que[j].time);
      }
    }
    if(cnt!=num-1){
      printf("\n");
    }
  }
  //最後に結果出力
  for(k = 0; k < num; k++){
    printf("%s %d ", fin[k].name, fin[k].time);
  }
  printf("\n");
  return 0;
}
