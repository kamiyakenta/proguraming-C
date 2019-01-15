#include <stdio.h>
#include <stdbool.h>

bool dfs(int y, char board[8][8]);
bool puttable(int y, int x, char board[8][8]);


int main (void){
  int i;
  char board[8][8];
  for(i = 0; i < 8; i++) scanf("%s", board[i]);

  if(dfs(0, board)){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return 0;
}

bool dfs(int y, char board[8][8]){
  if(y == 8) return true;
  int target = -1;
  for(int x = 0; x < 8; x++){
    if(board[y][x] == 'Q') {
      if(target != -1) return false;
        target = x;
    }
  }
  if(target != -1) {
    if(puttable(y, target, board)) {
      if(dfs(y + 1, board)) return true;
    }
  } else {
    for(int x = 0; x < 8; x++) {
      if(puttable(y, x, board)) {
        board[y][x] = 'Q';
        if(dfs(y + 1, board)) return true;
        board[y][x] = '.';
      }
    }
  }
  return false;
}

bool puttable(int y, int x, char board[8][8]) {
  for(int sy = -1; sy <= 1; sy++) {
    for(int sx = -1; sx <= 1; sx++) {
      if(sy == 0 && sx == 0) continue;
      int ty = y;
      int tx = x;
      while(true) {
        ty += sy; 
        tx += sx;
        if(ty < 0 || ty >= 8 || tx < 0 || tx >= 8) break;
        if(board[ty][tx] == 'Q') return false;
      }
    }
  }
  return true;
}
