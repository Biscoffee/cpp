#include <iostream>

using namespace std;

const int N = 15;
int n;
int path[N];  // 记录每行皇后所在的列（从 0 开始）
bool col[N], dg[2 * N], udg[2 * N];  // 列、主对角线、副对角线标记
int count_solutions = 0;  // 记录总解数

void dfs(int row) {
    if (row == n) {  
        count_solutions++;
        if (count_solutions <= 3) {  
            for (int i = 0; i < n; i++) {
                cout << path[i] + 1 << " ";  
            }
            cout << endl;
        }
        return;
    }

    for (int col_index = 0; col_index < n; col_index++) { 
        if (!col[col_index] && !dg[row + col_index] && !udg[row - col_index + n]) {
            // 放置皇后
            path[row] = col_index;
            col[col_index] = dg[row + col_index] = udg[row - col_index + n] = true;

            // 递归下一行
            dfs(row + 1);

            // 回溯
            col[col_index] = dg[row + col_index] = udg[row - col_index + n] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(0);  // 从第 0 行开始搜索
    cout << count_solutions << endl;  // 输出总解数
    return 0;
}