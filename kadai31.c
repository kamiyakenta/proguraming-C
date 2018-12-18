#include <stdio.h>
#include <stdlib.h>

int parent_id(int id) {
    return (id + 1)/2 - 1;
}

int left_id(int id) {
    return 2 * (id + 1) - 1;
}

int right_id(int id) {
    return 2 * (id + 1);
}

void print_info(int h, int* nodes, int id) {
    printf("node %d: key = %d, ", id + 1, nodes[id]);
    int parent = parent_id(id);
    if(0 <= parent) printf("parent key = %d, ", nodes[parent]);
    int left = left_id(id);
    if(left < h) printf("left key = %d, ", nodes[left]);
    int right = right_id(id);
    if(right < h) printf("right key = %d, ", nodes[right]);
    printf("\n");
}

int main() {
    int h; scanf("%d", &h);
    int* nodes = (int*)malloc(h*sizeof(int));
    int i = 0;
    for(i = 0; i < h; i++) {
        scanf("%d", &nodes[i]);
    }

    for(i = 0; i < h; i++) {
        print_info(h, nodes, i);
    }

}