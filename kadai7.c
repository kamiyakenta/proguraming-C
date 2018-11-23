#include <stdio.h>
#define N 100

int main(void){
  int n, q;
  int i, j;
  int flag = 0;
  int count =0;
  scanf("%d", &n);
  int S[n];
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  int T[q];
  for(i = 0; i < q; i++){
    scanf("%d", &T[i]);
  }
  printf("\n");

  //入力完了

  for(i = 0; i < q; i++){
    for(j = 0; j < n; j++){
      if(T[i] == S[j]){
        flag = 0;
        break;
      }else{
        flag = 1;
      }
    }
    if(flag == 1){
      count++;
      printf("%d ", T[i]);
      flag = 0;
    }
  }
  printf("\n");
  printf("%d\n", count);

  return 0;
}
