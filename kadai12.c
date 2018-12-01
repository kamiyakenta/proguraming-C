#include <stdio.h>

int main(void){
  int n;
  int i;
  int a[n];

  while(1){
    scanf("%d", &n);
    if(n==0) break;
    for(i=0; i<n; i++){
      scanf("%d", &a[i]);
    }
    printf("Hello\n");
  }

  return 0;
}
