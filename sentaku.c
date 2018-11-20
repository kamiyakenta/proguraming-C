#include <stdio.h>

void SimSelSort(int num[ ], int n);
void ShowData(int num[ ], int n);
int main(void);

void SimSelSort(int num[ ], int n){
    int i, j, k, max, temp;
    int count = 0;

    for (i = 0; i < n - 1; i++) {
        max = num[i];
        k = i;
        for (j = i + 1; j < n; j++) {
            if (num[j] > max) {
                max = num[j];
                k = j;
            }
        }
        count++;
        temp = num[k];
        num[k] = num[i];
        num[i] = temp;
    }
    printf("%d\n", count);
    ShowData(num, n);
}

void ShowData(int num[ ], int n){
    while (n--){
        if(n!=0){
            printf("%d ", *num++);
        }else{
            printf("%d\n", *num++);
        }
    }
}

int main(void){
    int n;
    int i;
    scanf("%d", &n);
    int num[n];
    for(i=0;i<n;i++)
        scanf("%d",&num[i]);
    SimSelSort(num, n);

    return 0;
}
