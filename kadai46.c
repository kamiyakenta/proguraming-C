// http://www.deqnotes.net/acmicpc/prim/ レジュメよりこっちの方がわかりやすい

#include <stdio.h>
#define MAX 100
#define infini 1e+9

int mincost[MAX];
int vis[MAX];

int min (int a, int b){
  if(a >= b) return b;
  else return a;
}

int prim(int N, int cost[N][N]) {
  int i;
  for(i = 0; i < MAX; ++i) {
      mincost[i] = infini;
      vis[i] = 0; //false
  }
  mincost[0] = 0;
  int ans = 0;

  while(1) {
    int v = -1;
    for(i = 0; i < N; i++) {
        if(vis[i]==0 && (v==-1 || mincost[i] < mincost[v])) v = i;
        // printf("---%d---\n", mincost[v]);
    }
    if (v == -1) break;
    vis[v] = 1; //訪れた
    // printf("...%d...\n", mincost[v]);
    ans += mincost[v];
    for(i = 0; i < N; i++) {
        mincost[i] = min(mincost[i], cost[v][i]);
    }
  }
  return ans;
}

int main (void){
  int i, j, N;
  scanf("%d", &N);
  int cost[N][N];

  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      scanf("%d", &cost[i][j]);
      if(cost[i][j]==-1) cost[i][j] = infini;
    }
  }
  int ans = prim(N, cost);
  printf("%d\n", ans);

  return 0;
}