#include <stdio.h>
#include <stdlib.h>

void InsSort(int num[ ], int n) ;
void ShowData(int num[ ], int n);
int main(void);
// 7 2 4 5 1 6

void InsSort(int num[ ], int n){
  int i, j, temp;
  int count = 0;
  for (i = 1; i < n; i++) {
      temp = num[i];
      for (j = i; j > 0 && num[j-1] < temp; j--){
          num[j] = num[j -1];
          count++;
      }
      num[j] = temp;
  }
  printf("%d\n", count);
  ShowData(num, n);
}

void ShowData(int num[ ], int n){
  while (n--)
    printf("%d ", *num++);
}

int main(void){
  int n;
  int i, j;
  scanf("%d", &n);
  int num[n];
  for(i=0;i<n;i++)scanf("%d",&num[i]);

  InsSort(num, n);
  return 0;
}
// 降順ソート
