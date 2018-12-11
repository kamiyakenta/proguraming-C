#include <stdio.h>

int min(int a[], int left, int right) {
  int s1,s2,ans;
  if(right == left) {
    ans = a[left];
  } else {
    s1 = min(a, left, (left + right)/2);
    s2 = min(a, (left + right)/2 + 1, right);
    if(s1 > s2){
      ans = s2;
    }else{
      ans = s1;
    }
  }
  printf("%d\n", ans);
  return ans;
}

int main(void) {
  int ans;
  int i;
  int n;
  scanf("%d", &n);
  int a[n];
  for(i = 0; i < n; i++){
    scanf("%d",&a[i]);
  }
  ans = min(a, 0 ,n-1);
  return 0;
}
