#include <stdio.h>
#include <ctype.h>
void init(int);
int dep(int);
int inp(void);

int content[100000];
char *p;
char in[15000];
int tree[100000][15],idx[100000];

int main(){
  int n,i,j,id,k,c;

  fread(in,sizeof(in),1,stdin);
  p = in;

  n = inp();
  init(n);
  for(i=0; i<n; i++){
   id = inp();
   k = inp();
   for(j=0; j<k ;j++){
     c = inp();
     content[c] = id;
     tree[id][idx[id]++] = c;
   }
  }

  for(i=0; i<n; i++){
   printf("%d %d %d\n",i,content[i],dep(i));
  }

  return 0;
}

void init(int n){ //初期化
  int i;
  for(i=0; i<n; i++){
   content[i] = -1;
  }
}

int dep(int x){ //深さのカウント
  if(content[x] == -1) return 0;
  int d = dep(content[x]) + 1;
  return d;
}

int inp(){
  int a = 0;
  while(!isdigit(*p)) p++;
  a = *p++&15;
  while(isdigit(*p)){
   a = (a<<3)+(a<<1)+(*p++&15);
  }
  return a;
}
