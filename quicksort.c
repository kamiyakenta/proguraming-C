#include<stdio.h>

void ShowData(int a[ ], int n){
  int i;
  for (i = 0; i < n ; i++){
    printf("%d ", a[i]);
  }
  printf("\n");
}

void Swap(int a[ ], int i, int j){
  int temp;
  temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}


void QSort(int a[ ], int left, int right){
  int i, j;
  int pivot;

  i = left;
  j = right;

  pivot = a[(left + right) / 2];

  while (1) {
    while (a[i] < pivot){
      i++;
    }

    while (pivot < a[j]){
      j--;
    }
    if (i >= j){
      break;
    }

    Swap(a, i, j);
    i++;
    j--;
  }
  ShowData(a, 10);

  if (left < i - 1)
      QSort(a, left, i - 1);
  if (j + 1 <  right)
      QSort(a, j + 1, right);
}



int main(void){
  int n;
  scanf("%d", &n);
  int i;
  int a[n];
  for(i=0; i<n; i++){
    scanf("%d", &a[i]);
  }

  printf("ソート前:\n");
  ShowData(a, n);

  printf("ソート中:\n");
  QSort(a, 0, n - 1);

  printf("ソート後:\n");
  ShowData(a, n);

  return 0;
}
