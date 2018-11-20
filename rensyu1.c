// Maximum Profit
//  You can obtain profits from foreign exchange margin transactions. For example, if you buy 1000 dollar at a rate of 100 yen per dollar, and sell them at a rate of 108 yen per dollar, you can obtain (108 - 100) × 1000 = 8000 yen.

//  Write a program which reads values of a currency Rt at a certain time t (t=0,1,2,...n−1), and reports the maximum value of Rj−Ri where j>i .

// Input
//  The first line contains an integer n. In the following n lines, Rt (t=0,1,2,...n−1) are given in order.

// Output
//  Print the maximum value in a line.



#include <stdio.h>

int main(void){
  int n;
  int i, j;
  int tmp = -100;
  scanf("%d", &n);
  int a[n];


  for (i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  for (i = 0; i < n-1; i++){
    for (j = i; j < n; j++){
      if((a[j] - a[i]) > tmp){
        tmp = a[j] - a[i];
      }
    }
  }

  printf("%d\n", tmp);

  return 0;
}


