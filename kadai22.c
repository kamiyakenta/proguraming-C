// 与えられたN個の数列A（a0, a1, …, aN-1）について降順に並んでいることを期待するとき、期待に反して ai < aj （ただし i < j）となってしまっている要素対の個数を求めなさい。例えば下記の例では、a0 と a1 および a0 と a2 の両対について ai < aj となっている。

// 入力: 1行目にN、2行目に空白区切りによる数列A
// 出力: 対の個数を出力して改行
// 制約: 1 <= N <= 200,000, 0 <= Aの要素 <= 1,000,000,000, Aの要素はすべて異なる
// 参考: ALDS

// 入力例:
// 3
// 1 3 2

// 出力例:
// 2


#include  <stdio.h>

void BubSort(int x[ ], int n);
int main(void);

void BubSort(int x[ ], int n){
    int i, j, temp;
    int count = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (x[j - 1] < x[j]) {
                temp = x[j];
                x[j] = x[j - 1];
                x[j - 1]= temp;
                count ++;
            }
        }
    }
    printf("%d\n", count);
}


int main(void){
    int n;
    int i, j;
    scanf("%d", &n);
    int num[n];
    for(i=0;i<n;i++)scanf("%d",&num[i]);

    BubSort(num, n);
    return 0;
}
