#include <stdio.h>

int temp[100];
int count = 0;

void MergeSort(int x[ ], int left, int right){
  int mid, i, j, k;
  if(left >= right) return; //分割し終わり

  mid = (left + right) / 2;
  count++;
  MergeSort(x, left, mid);
  MergeSort(x, mid + 1, right);

      /* x[left] から x[mid] を作業領域にコピー */
  for (i = left; i <= mid; i++)
    temp[i] = x[i];

      /* x[mid + 1] から x[right] は逆順にコピー */
  for(i = mid + 1, j = right; i <= right; i++, j--)
    temp[i] = x[j];

  i = left;         /* i とj は作業領域のデーターを */
  j = right;        /* k は配列の要素を指している */

  for (k = left; k <= right; k++)    /* 小さい方から配列に戻す */
    if (temp[i] >= temp[j])        /* ここでソートされる */
      x[k] = temp[i++];
    else
      x[k] = temp[j--];   //ここで後ろからやりたいからさっき逆順にコピーした
}

int main(void){
  int i, n;
  scanf("%d", &n);
  int x[n];

  for(i = 0; i < n; i++){
    scanf("%d", &x[i]);
  }

  MergeSort(x, 0, n - 1);

  for (i = 0; i < n; i++)
    if(i == n-1) printf("%d", x[i]);
    else printf("%d ", x[i]);
  printf("\n");
  printf("%d\n", count);
  return 0;
}
