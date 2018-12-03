// 非負整数nが与えられたとき、nの階乗を再帰的に求めて出力しなさい。ただし0! = 1と定義する。

#include <stdio.h>

unsigned int N;

long int factorial(int n) {
    if (n > 0) {
        return n * factorial(n - 1);
    } else {
        return 1;
    }
}

int main(void){
    scanf("%d\n", &N);
    unsigned long int result = factorial(N);
    printf("%ld\n", result);
    return 0;
}
