#include <stdio.h>
#include <stdlib.h>

int left_id(int id) {
    return 2 * (id + 1) - 1;
}

int right_id(int id) {
    return 2 * (id + 1);
}

void max_heapify(int h, int* a, int id) {
    int l = left_id(id), r = right_id(id);
    int largest = id;
    if(l < h) largest = a[l] > a[largest]? l : largest;
    if(r < h) largest = a[r] > a[largest]? r : largest;

    if(largest != id) {
        int temp = a[id];
        a[id] = a[largest];
        a[largest] = temp;
        max_heapify(h, a, largest);
    }
}

void bulid_max_heap(int h, int* a) {
    int i;
    for(i = h/2 - 1; i >= 0; i--) {
        max_heapify(h, a, i);
    }
}

int main() {
    int h; scanf("%d", &h);
    int i = 0;
    int* nodes = (int*)malloc(h*sizeof(int));
    for(i = 0; i < h; i++) {
        scanf("%d", &nodes[i]);
    }
    bulid_max_heap(h, nodes);
    for(i = 0; i < h; i++) {
        printf(" %d", nodes[i]);
    }
    printf("\n");
}