#include <stdio.h>

int main(void){
  int i, j;
  int n, m;
  while(1){
    scanf("%d %d", &n, &m);
    char a[n][m];
    int all = 0;
    if(n==0 && m==0) break;

    for(i = 0; i < n; i++){
      for(j = 0; j < m; j++){
        scanf("%s", &a[i][j]);
        if(a[i][j]=='.'){
          all++;
        }
      }
    }
    if(a[0][0]=='.' && a[0][1]=='#' && a[1][0]=='#') all--;
    if(a[0][m-1]=='.' && a[0][m-2]=='#' && a[1][m-1]=='#') all--;
    if(a[n-1][0]=='.' && a[n-2][0]=='#' && a[n-1][1]=='#') all--;
    if(a[n-1][m-1]=='.' && a[n-1][m-2]=='#' && a[n-2][m]=='#') all--;

    for(i = 1; i < n-1; i++){
      for(j = 1; j < m-1; j++){
        if(a[i][j]=='.'){
          if(a[i-1][j]=='#' && a[i+1][j]=='#' && a[i][j-1]=='#' && a[i][j+1]=='#'){
            all--;
          }
        }
      }
    }
    printf("%d\n", all+1);
  }
  return 0;
}
