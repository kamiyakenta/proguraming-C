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
