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
    
void insert(int count, int z){
    int x=0, y;
    if(count==0) x=-1;
    
    A[count].value = z;
    A[count].left = -1;
    A[count].right = -1;
    
    while(x>=0){
        y = x; 
        if(z < A[x].value)x = A[x].left; 
        else x = A[x].right; 
    }
    if(count<1){}
    else if(z < A[y].value)A[y].left = count; 
    else A[y].right = count; 
}

int search(int node, int num){
    int t; 
    t = num - A[node].value;
    if (t==0) return 1;
    if (t < 0) {
        if (A[node].left > 0) return search(A[node].left, num);
    } else if (t > 0) {
        if (A[node].right > 0) return search(A[node].right, num);
    }
    return 0;
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
        
    while(1){
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
    
}

int main(){
    char s[8];
    int n;
    int num;
    int count=0;
    int i;
    int flag = 0;
    scanf("%d", &n);  
    for(i=0; i<n; i++){
        scanf("%s", s);
        if(strcmp(s, "insert") == 0){ //insert
            scanf("%d", &num); 
            insert(count, num); 
            count++; 
        }
        if(strcmp(s, "find") == 0){ //find
            scanf("%d", &num);
            flag = search(0, num);
            if (flag) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }

        if(strcmp(s, "delete") == 0){ //delete
            scanf("%d", &num);
            delete(num);
        }

        if(strcmp(s, "print") == 0){ //print
            if(count>0) inParse(0);
            printf("\n");
            if(count>0) preParse(0);
            printf("\n");
        }
    }  
    return 0;  
}
