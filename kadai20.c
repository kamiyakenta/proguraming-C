#include <stdio.h>
int count = 0;

//一番最初に異なる値で大きほうをpivotにする。全部同じ値は何もしない(return -1)
int pivot(int a[], int i, int j){
  int k = i+1;
  while(k <= j && a[i] == a[k]) k++;
  if(k > j) return -1;
  if(a[i] < a[k]){
    count++;
    return i;
  }
  return k;
}

int partition(int a[], int i, int j, int p){
  int left = i;
  int right = j;

  while(left <= right){
    // 軸要素以上のデータを探す
    while(left <= j && a[left] > p)  left++;
    // 軸要素未満のデータを探す
    while(right >= i && a[right] <= p) right--;
    if(left > right){
      break;
    }
    int t = a[left];
    a[left] = a[right];
    a[right] = t;
    left++;
    right--;
  }
  return left;
}


void quickSort(int a[], int i, int j){
  if(i == j) return;
  int p = pivot(a, i, j);
  if(p != -1){
    int k = partition(a, i, j, a[p]);
    quickSort(a, i, k-1);
    quickSort(a, k, j);
  }
}

int main(void){
  int n;
  int i;
  scanf("%d", &n);
  int a[n];
  for(i=0; i<n; i++){
    scanf("%d", &a[i]);
  }

  quickSort(a, 0, n-1);

  for (i = 0; i < n; i++)
    if(i == n-1) printf("%d", a[i]);
    else printf("%d ", a[i]);
  printf("\n");
  printf("%d\n", count);

  return 0;
}
