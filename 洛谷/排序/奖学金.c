#include <stdio.h>

struct student {
    int ch;  
    int ma;  
    int en;  
    int id;  
    int total;  
};
int quick_sort(a[], int l, int r){
    
} 
int main() {
    int n;
    scanf("%d", &n);  
    struct student a[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a[i].ch, &a[i].ma, &a[i].en);
        a[i].id = i + 1;  
        a[i].total = a[i].ch + a[i].ma + a[i].en;  
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j].total < a[j + 1].total) {
                struct student temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            } else if (a[j].total == a[j + 1].total) {
                if (a[j].ch < a[j + 1].ch) {
                    struct student temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                } else if (a[j].ch == a[j + 1].ch) {
                    if (a[j].id > a[j + 1].id) {
                        struct student temp = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("%d %d\n", a[i].id, a[i].total);
    }

    return 0;
}