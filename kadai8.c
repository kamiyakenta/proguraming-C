#include <stdio.h>
#define N 100

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
  }

  scanf("%d", &q);
  int T[q];
  for(i = 0; i < q; i++){
    scanf("%d", &T[i]);
  }

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
      a[count] = T[i];
      count++;
      flag = 0;
    }
  }
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
