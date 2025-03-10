#include <iostream>
#include <vector>
using namespace std;

int n,m,t;
int sx,sy,fx,fy;
vector<vector<int>> a; //
vector<vector<bool>> visited; 
int count = 0;

void dfs(int x, int y) {
    if (x == fx && y == fy) {
        count++;
        return;
    }

    visited[x][y] = true;

    // 上下左右四个方向
    if (x > 1 && a[x - 1][y] == 0 && !visited[x - 1][y]) {
        dfs(x - 1, y);
    }
    if (x < n && a[x + 1][y] == 0 && !visited[x + 1][y]) {
        dfs(x + 1, y);
    }
    if (y > 1 && a[x][y - 1] == 0 && !visited[x][y - 1]) {
        dfs(x, y - 1);
    }
    if (y < m && a[x][y + 1] == 0 && !visited[x][y + 1]) {
        dfs(x, y + 1);
    }

    visited[x][y] = false; 
}

int main() {
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;

    a = vector<vector<int>>(n + 1, vector<int>(m + 1));
    visited = vector<vector<bool>>(n + 1, vector<bool>(m + 1, false));

    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1; 
    }

    dfs(sx, sy);

    cout << count << endl;

    return 0;
}