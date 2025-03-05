#include <iostream>

using namespace std;

const int N = 100010;

int n;
int path[N]; // 记录路径 存方案
bool st[N];  // 记录状态 存状态 

void dfs(int u)
{
    if(u == n)
    {
        for(int i = 0;i < n;i++)  printf("%d ",path[i]);
        cout << endl;
        return;
    } 
    for(int i = 1;i <= n;i++){
        if(!st[i]){
            path[u] = i;
            st[i] = true;
            dfs(u + 1);
            st[i] = false;
        }
    }
}
int main()
{
    cin  >> n;
    dfs(0);
    return 0;
}