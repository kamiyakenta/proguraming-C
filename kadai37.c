#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int memo[n+1];
    memo[0] = 1;
    memo[1] = 1;
    for(int i=2; i<=n; i++){
        memo[i] = memo[i-1] + memo[i-2];
    }

    for(int i=0; i<=n ;i++){
        if(i>0) printf(" ");
        printf("%d", memo[i]);
    }

    return 0;
}