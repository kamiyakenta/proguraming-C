#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100000

int find[N];

void init(int n){
  for(int i = 0; i < n; ++i) { find[i] = i; }
}

int root(int x) {
  if(x != find[x]) {
      find[x] = root(find[x]);
  }
  return find[x];
}

void merge(int s, int t){
  find[root(s)] = root(t);
}

bool query(int s, int t){
  if (root(s) == root(t)) return true;
  else return false;
}

int main() {
  int n, m, s, t;
  scanf("%d %d", &n, &m);

  init(n);
  for(int i = 0; i < m; ++i) {
      scanf("%d %d", &s, &t);
      merge(s, t);
  }

  scanf("%d %d", &s, &t);
  if (query(s, t)) printf("true\n");
  else printf("false\n");

  return 0;
}