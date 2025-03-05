#include <stdio.h>
#include <stdlib.h>


int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    qsort(a, n, sizeof(int), cmp);

    int result[n];
    int count = 0;
    
    result[count++] = a[0]; 
    
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            result[count++] = a[i];  
        }
    }
    

    printf("%d\n", count);  
    for (int i = 0; i < count; i++) {
        printf("%d", result[i]);
        if (i < count - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}