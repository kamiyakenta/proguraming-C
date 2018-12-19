// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_8_C#
/*  sample input
18
insert 8
insert 2
insert 3
insert 7
insert 22
insert 1
find 1
find 2
find 3
find 4
find 5
find 6
find 7
find 8
print
delete 3
delete 7
print
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int value;
    int parent;
    int left;
    int right;
}Node;
 
Node A[500000];

void inParse(int p){
    if(A[p].left>=0) inParse(A[p].left);
    printf(" %d", A[p].value);
    if(A[p].right>=0) inParse(A[p].right);
}
    
void preParse(int p){
    printf(" %d", A[p].value);
    if(A[p].left>=0) preParse(A[p].left);
    if(A[p].right>=0) preParse(A[p].right);
}

void insert(int z){
    int x = 0;
    int y = -1;
    
    if(z != 0)
        while(x != -1){
            y = x;
            if(A[z].value < A[x].value) x = A[x].left;
            else x = A[x].right;
        }
    
    A[z].parent = y;
    
    if(y != -1){
        if(A[z].value < A[y].value) A[y].left = z;
        else A[y].right = z;
    }
    return ;
}

void search(int x, int k){
    if(x == -1) printf("no\n");
    else if(A[x].value == k) printf("yes\n");
    else if(k < A[x].value) search(A[x].left, k);
    else if(k > A[x].value) search(A[x].right, k);
}

int successor(int x){
    int y;
    if(A[x].right != -1){
        x = A[x].right;
        while(A[x].left != -1) x = A[x].left;
        return x;
    }else{
        y = A[x].parent;
        while(y != -1 && x == A[y].right){
            x = y;
            y = A[y].parent;
        }
        return y;
    }
}
 
void delete(int k){
    int x, y, z = 0;

    while(1){ //探す
        if(A[z].value == k) break;
        else if(k < A[z].value) z = A[z].left;
        else z = A[z].right;
    }

    if(A[z].left == -1 || A[z].right == -1) y = z;
    else y = successor(z);

    if(A[y].left != -1) x = A[y].left;
    else x = A[y].right;

    if(x != -1) A[x].parent = A[y].parent;

    if(A[y].parent != -1){
        if(y == A[A[y].parent].left) A[A[y].parent].left = x;
        else A[A[y].parent].right = x;
    }
    if(y !=  z) A[z].value = A[y].value;
    return ;
}

int main(){
    int i, n;
    int num;
    char s[7];
    scanf("%d", &n);

    for(i=0; i<n; i++){
        A[i].left = -1;
        A[i].right = -1;
        scanf("%s", s);
    
        if(strcmp(s, "insert") == 0){
            scanf("%d", &A[i].value);
            insert(i);
        }else if(strcmp(s, "print") == 0){
            inParse(0);
            printf("\n");
            preParse(0);
            printf("\n");
        }else if(strcmp(s, "find") == 0){
            scanf("%d", &num);
            search(0, num);
        }else if(strcmp(s, "delete") == 0){
            scanf("%d", &num);
            delete(num);
        }
    }
    return 0;
}
