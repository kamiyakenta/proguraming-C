#include <stdio.h>
#include <stdlib.h>

int flag;

int asc(const void *a, const void *b){
  return *(int *)a - *(int *)b;
}


void f(int start, int sum, int num, int a[], int b, int n){
  int i;
  if(flag == 2) return; //もう終わったら何もしないで戻る

  if(a[0]>b){
    printf("false\n");
    return;
  }

  if(sum==b){
    printf("true\n");
    flag = 2;
    return;
  }

  if(sum>b) return;

  if(sum!=b && num == 0){
    flag = 1;
  }

  for(i=start;i<n;i++){
    f(i+1, sum+a[i], num+1, a, b, n);
  }
  if(sum!=b && num == 0){
    if(flag == 1){
      printf("false\n");
    }
    return;
  }

  return;
}

int main(void){
  int n, m, i;
  scanf("%d", &n);
  int a[n];
  for(i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
  scanf("%d", &m);
  int b[m];
  for(i=0; i<m; i++){
    scanf("%d", &b[i]);
  }

  qsort(a, n, sizeof(int), asc);
  qsort(b, n, sizeof(int), asc);

  for(i=0; i<m; i++){
    flag = 0;
    f(0, 0, 0, a, b[i], n);
  }

  return 0;
}
