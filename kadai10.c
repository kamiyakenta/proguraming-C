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
