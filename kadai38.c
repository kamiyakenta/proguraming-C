#include <stdio.h>
#include <string.h>
#define N 21

char map[N][N];
int count[N][N] = {0};
int W, H;

void search(int i, int j) {
  count[i][j]++;
  if (i < H-1 && map[i+1][j] != 'X') search(i+1, j);
  if (j < W-1 && map[i][j+1] != 'X') search(i, j+1);
}

int main(void) {

  int i, j;
  scanf("%d %d", &W, &H);
  for (i = 0; i < H; i++) scanf("%s", map[i]);
  
  search(0,0);
  printf("%d\n", count[H-1][W-1]);
  
  return 0;
}