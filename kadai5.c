#include <stdio.h>
#define MAX_N 100

typedef struct Pro {
  char name[100];
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

  for(cnt = 0, time = 0; cnt < num;) {

    if (q < que[0].time){
      tmp = q;  //クォンタムより大きかったらクォンタム分のみ
    }else{
      tmp = que[0].time;  //クォンタムより小さかったらそのプロセスのタイム
    }

    que[0].time -= tmp;

    time += tmp;
    int flag = 0;
    //もうプロセス終了したら結果にいれる
    if(que[0].time <= 0) {
      fin[k] = que[0];
      fin[k].time = time;
      k++;
      cnt++;
      flag = 1;
    }

    //キューの循環
    tmp2 = que[0];
    for (j = 1; j < num; j++){
      que[j-1] = que[j];
    }
    if(flag == 0){
      que[num-1-cnt] = tmp2;
    }else{
      que[num-cnt] = tmp2;
    }

    //毎度キューの中身を全て出力
    for(j = 0; j < num; j ++){
      if(que[j].time != 0){
        printf("%s %d", que[j].name, que[j].time); //WOJのため
        //printf("%s %d ", que[j].name, que[j].time);
      }
    }

    //WOJのための出力合わせ
    if (num == 1){
      if(cnt==num-1){
        printf("\n");
      }
    }else{
      if(cnt!=num-1){
        printf("\n");
      }
    }

  }
  //最後に結果出力(WOJのために条件分岐)
  for(k = 0; k < num; k++){
    if(k != num-1){
      printf("%s %d ", fin[k].name, fin[k].time);
    }else{
      printf("%s %d", fin[k].name, fin[k].time);
    }
  }
  printf("\n");
  return 0;
}
