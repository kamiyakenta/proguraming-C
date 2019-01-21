#include <bits/stdc++.h>
using namespace std;
#define SIZE 10

int Map[SIZE][SIZE];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

inline bool isMapRange(const int i, const int j){
    return 0 <= i && i < SIZE && 0 <= j && j < SIZE;
}

queue<pair<pair<int, int>, int> > que;

int search(pair<int, int> &g){
  pair<pair<int, int>, int> cc = que.front();
  que.pop();

  if (cc.first == g)
    return cc.second;

  for (int i = 0; i < 4; i++){
    if (isMapRange(cc.first.first + dx[i], cc.first.second + dy[i]) && Map[cc.first.first + dx[i]][cc.first.second + dy[i]] == 1){
      Map[cc.first.first + dx[i]][cc.first.second + dy[i]] = 0;
      que.push(pair<pair<int, int>, int>(pair<int, int>(cc.first.first + dx[i], cc.first.second + dy[i]), cc.second + 1));
    }
  }
  return search(g);
}

int main(){
  pair<int, int> start, goal;
  for (int j = 0; j < SIZE; j++){
    string line;
    cin >> line;
    for (int i = 0; i < SIZE; i++){
      switch (line[i]){
      case '#':
        Map[j][i] = 0;
        break;
      case '.':
        Map[j][i] = 1;
        break;
      case 'S':
        Map[j][i] = 1;
        start.first = j;
        start.second = i;
        break;
      case 'G':
        Map[j][i] = 1;
        goal.first = j;
        goal.second = i;
        break;
      default:
        break;
      }
    }
  }

  que.push(pair<pair<int, int>, int>(start, 0));
  printf("%d\n", search(goal));

  return 0;
}