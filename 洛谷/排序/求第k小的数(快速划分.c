#include <stdio.h>
#include <stdlib.h>

// 划分函数，返回基准元素的最终位置
int partition(int arr[], int left, int right) {
    int pivot = arr[left];  // 选择基准元素
    int i = left, j = right;

    while (i < j) {
        // 找到比基准大的元素
        while (i < j && arr[j] >= pivot)
            j--;
        if (i < j) arr[i] = arr[j];

        // 找到比基准小的元素
        while (i < j && arr[i] <= pivot)
            i++;
        if (i < j) arr[j] = arr[i];
    }

    arr[i] = pivot;
    return i;
}

// 快速选择函数
int quick_select(int arr[], int left, int right, int k) {
    if (left == right) {
        return arr[left];
    }

    int pivot_index = partition(arr, left, right);

    // 基准元素的位置是pivot_index
    if (k == pivot_index) {
        return arr[k];
    } else if (k < pivot_index) {
        return quick_select(arr, left, pivot_index - 1, k);  // 在左边
    } else {
        return quick_select(arr, pivot_index + 1, right, k); // 在右边
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = quick_select(arr, 0, n - 1, k);  // 使用快速选择算法
    printf("%d\n", result);

    return 0;
}