#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    // 计算正方形的数量
    int square_count = 0;
    int max_side = n < m ? n : m;
    for (int k = 1; k <= max_side; ++k) {
        square_count += (n - k + 1) * (m - k + 1);
    }
    //(n - k + 1)：这是纵向可以放置边长为 k 的正方形的数量。因为正方形的边长为 k，所以只能从第 1 行到第 n-k+1 行放置。
    //(m - k + 1)：这是横向可以放置边长为 k 的正方形的数量。同理，正方形的边长为 k，只能从第 1 列到第 m-k+1 列放置。
    // 计算矩形的数量
    long long total_rectangles = (long long)(n * (n + 1)) / 2 * (long long)(m * (m + 1)) / 2;
    //横向边的选择方式是 n(n + 1) / 2 = 3 * 4 / 2 = 6。
    //纵向边的选择方式是 m(m + 1) / 2 = 4 * 5 / 2 = 10。
    // 长方形数量 = 矩形数量 - 正方形数量
    long long rectangle_count = total_rectangles - square_count;
    
    // 输出结果
    printf("%d %lld\n", square_count, rectangle_count);
    
    return 0;
}