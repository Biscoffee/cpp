#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int m;  
    int v;  
    double unit_value;  
} Item;

int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    if (itemA->unit_value < itemB->unit_value) {
        return 1;
    } else if (itemA->unit_value > itemB->unit_value) {
        return -1;
    }
    return 0;
}

int main() {
    int N, T;
    scanf("%d %d", &N, &T);
    
    Item items[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &items[i].m, &items[i].v);
        items[i].unit_value = (double)items[i].v / items[i].m;
    }
    qsort(items, N, sizeof(Item), compare);
    
    double total_value = 0.0;
    int remaining_capacity = T;
    for (int i = 0; i < N; i++) {
        if (remaining_capacity == 0) {
            break;
        }
        
        if (items[i].m <= remaining_capacity) {
            total_value += items[i].v;
            remaining_capacity -= items[i].m;
        } else {
            total_value += items[i].unit_value * remaining_capacity;
            remaining_capacity = 0;
        }
    }
    
    printf("%.2f\n", total_value);
    
    return 0;
}