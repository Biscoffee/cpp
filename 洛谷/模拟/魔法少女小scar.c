#include <stdio.h>

void xuanzhuan(int x, int y, int r, int z, int a[505][505]) {
    int b[505][505];
    for (int i = x - r; i <= x + r; i++) {
        for (int j = y - r; j <= y + r; j++) {
            if (z == 0) 
                b[i][j] = a[x + y - j][y - x + i];  // 顺时针旋转
            else 
                b[i][j] = a[x - y + j][x + y - i];  // 逆时针旋转
        }
    }
    for (int i = x - r; i <= x + r; i++) {
        for (int j = y - r; j <= y + r; j++) {
            a[i][j] = b[i][j];
        }
    }
}

int main() {
    int n, m, a[505][505], x, y, r, z, mark = 1;
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = mark++;
        }
    }
    
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &x, &y, &r, &z);
        xuanzhuan(x, y, r, z, a);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}