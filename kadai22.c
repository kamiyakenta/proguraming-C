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
