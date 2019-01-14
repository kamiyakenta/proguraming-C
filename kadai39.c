#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1001
char X[MAX];
char Y[MAX];
int lcs(int k,int t);

int main(){
  int q, i, ans;
  int l1,l2;
  scanf("%s", X);
  scanf("%s", Y);
  l1 = strlen(X);
  l2 = strlen(Y);
  ans = lcs(l1, l2);
  printf("%d\n", ans);
  return 0; 
}

int lcs(int k, int s){
  int i, j;
  int t[MAX][MAX];
  for(i = 0;i <= k;i++){
    t[i][0] = 0;
  }
  for(i = 0;i <= s;i++){
    t[0][j] = 0; 
  }
  for(i = 1;i <= k;i++){
    for(j = 1;j <= s;j++){
      if(X[i-1] == Y[j-1]){
        t[i][j] = t[i-1][j-1]+1;
      }else if(t[i-1][j-1] >= t[i][j-1]){
        t[i][j] = t[i-1][j];
      }else{
        t[i][j] = t[i][j-1];
      } 
    }
  }
  if(i == 0 || j == 0){
    return 0;
  }else if(i > 0 && j > 0 && k == s){
    return t[i-1][j-1];
  }else if(i > 0 && j > 0 && k != s){
    return t[k][s];
  }
  return 0; 
}