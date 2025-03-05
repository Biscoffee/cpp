#include <stdio.h>
#include <math.h>
#include <string.h>

int l, n, m;
int rocks[50010];

int check(int d) {
    int removed = 0;
    int last = 0;
    for (int i = 0; i < n; i++) {
        if (rocks[i] - last < d) {
            removed++;
        } else {
            last = rocks[i];
        }
    }
    if (l - last < d) {
        removed++;
    }
    return removed <= m;
}

int main() {
    scanf("%d %d %d", &l, &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &rocks[i]);
    }

    int left = 0, right = l;  
    int min_dis = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            min_dis = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("%d\n", min_dis);

    return 0;
}