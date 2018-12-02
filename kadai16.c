#include <stdio.h>
#include <math.h>

int main(void){
  int m, n;
  double ext;
  double ans;

  scanf("%d %d", &m, &n);

  ext = m - n;
  ans = pow((double)n, ext);

  printf("%d\n", (int)ans);

  return 0;
}
