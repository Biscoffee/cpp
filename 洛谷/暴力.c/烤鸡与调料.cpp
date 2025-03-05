#include <iostream>
#include <vector>
using namespace std;

int n; // 美味程度
vector<vector<int>> solutions; // 存放所有解

// 当前选择放置的配料下标 pos，当前累计和 curSum，当前方案 cur
void dfs(int pos, int curSum, vector<int>& cur) {
    if (pos == 10) {
        if (curSum == n) {
            solutions.push_back(cur);
        }
        return;
    }
    
    // 剩余配料个数
    int remain = 10 - pos;
    // 剩余最小可能的和（每个至少 1）和最大可能的和（每个最多 3）
    int minRemain = remain;
    int maxRemain = remain * 3;
    
    // 枚举当前配料可以放的克数：1, 2, 3（按字典序）
    for (int i = 1; i <= 3; i++) {
        // 剩余的总和需要在合法区间内
        if (curSum + i + minRemain - 1 > n || curSum + i + maxRemain - 3 < n)
            ; // 用于剪枝，但本题数据较小，可以不剪枝
        // 检查剪枝条件：剩余部分的和必须至少达到 n - (curSum+i)
        if (curSum + i + (remain - 1) > n || curSum + i + (remain - 1) * 3 < n)
            continue;
        
        cur.push_back(i);
        dfs(pos + 1, curSum + i, cur);
        cur.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    
    // 如果 n 不在 10～30 之间，则不可能有符合要求的方案
    if(n < 10 || n > 30) {
        cout << 0 << "\n";
        return 0;
    }
    
    vector<int> cur;
    dfs(0, 0, cur);
    
    // 输出方案总数
    cout << solutions.size() << "\n";
    
    // 按字典序输出：递归过程中按 1,2,3 枚举已经保证了字典序
    for (auto &sol : solutions) {
        for (int x : sol)
            cout << x << " ";
        cout << "\n";
    }
    
    return 0;
}