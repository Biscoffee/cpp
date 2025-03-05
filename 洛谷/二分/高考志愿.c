#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

// 寻找最接近学生估分的学校分数
int find_closest_school(int a[], int m, int score) {
    int l = 0, r = m - 1;
    
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] < score) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    if (l > 0 && abs(a[l - 1] - score) <= abs(a[l] - score)) {
        return a[l - 1];
    } else {
        return a[l];
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    int a[m]; 
    int b[n]; 

    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    qsort(a, m, sizeof(a[0]), cmp);
    
    int total_discontent = 0;

    for (int i = 0; i < n; i++) {
        int closest_school = find_closest_school(a, m, b[i]);
        total_discontent += abs(closest_school - b[i]);
    }
    
    printf("%d\n", total_discontent);
    
    return 0;    
}