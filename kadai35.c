#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int heap[(int)1e6];

int left_id(int id) {
    return 2 * (id + 1) - 1;
}

int right_id(int id) {
    return 2 * (id + 1);
}

void max_heapify(int h, int id) {
    int l = left_id(id), r = right_id(id);
    int largest = id;
    if(l < h) largest = heap[l] > heap[largest]? l : largest;
    if(r < h) largest = heap[r] > heap[largest]? r : largest;

    if(largest != id) {
        int temp = heap[id];
        heap[id] = heap[largest];
        heap[largest] = temp;
        max_heapify(h, largest);
    }
}

void bulid_max_heap(int h) {
    int i;
    for(i = h/2 - 1; i >= 0; i--) {
        max_heapify(h, i);
    }
}

int main() {
    int h = 0;
    char inst[10];
    while(1) {
        scanf("%s", inst);
        if(strcmp(inst, "end") == 0) break;
        else if(strcmp(inst, "extract") == 0) {
            bulid_max_heap(h);
            printf("%d\n", heap[0]);
            int i;
            for(i = 0; i < h; i++) {
                heap[i - 1] = heap[i];
            }
            h--;
        }
        else if(strcmp(inst, "insert") == 0) {
            int e;
            scanf("%d", &e);
            heap[h] = e;
            h++;
        }
    }
}