#include <stdio.h>
#include <stdlib.h>
#define NIL -1
#define infini 1e+9
#define N 101

int main(void) {
  int n, i, j, s, t, k, l;
  int mincost = 0;
  int G[N][N], cost[N], pi[N], flag[N];

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      G[i][j] = infini;
    }
  }

  for(i = 0; i < n; i++){
    scanf("%d%d", &s, &k);
    for(j = 0; j < k; j++){
      scanf("%d %d", &t, &l);
      G[s][t] = l;
    }
  }

  for(i = 0; i < n; i++){
    cost[i] = infini;
    pi[i] = NIL;
    flag[i] = 1;
  }

  cost[0] = 0;
  while(1){
    mincost = infini;
    for(i = 0; i < n; i++){
        if(flag[i] != 2 && cost[i] < mincost){
            mincost = cost[i];
            s = i;
        }
    }
    if(mincost == infini) break;
    flag[s] = 2;
    for(i = 0; i < n; i++){
      if(cost[i] > cost[s] + G[s][i]){
        cost[i] = cost[s] + G[s][i];
        pi[i] = s;
      }
    }
  }

  for(i = 0; i < n; i++){
    printf("%d %d\n", i, cost[i]);
  }

  return 0;
}