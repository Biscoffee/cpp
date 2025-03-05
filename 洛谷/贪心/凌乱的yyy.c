#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start; 
    int end;  
} Event;

int compare(const void *a, const void *b) {
    Event *eventA = (Event *)a;
    Event *eventB = (Event *)b;
    return eventA->end - eventB->end; 
}

int main() {
    int n;
    scanf("%d", &n);
    
    Event events[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &events[i].start, &events[i].end);
    }

    qsort(events, n, sizeof(Event), compare);

    int count = 0;       
    int last_end_time = -1;  

    for (int i = 0; i < n; i++) {
        if (events[i].start >= last_end_time) {
            count++;
            last_end_time = events[i].end; 
        }
    }

    printf("%d\n", count);
    return 0;
}