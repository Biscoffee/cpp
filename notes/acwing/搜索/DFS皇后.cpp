#include <iostream>

using namespace std;

const int N = 20;
int n;
int g[N][N];
bool col[N],dg[N],udg[N];

void dfs(int v)
{
    if(v == n)
    {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << g[i][j];
            }
            cout << endl;
        }
        puts("");
        return;
    }
    for(int i = 0;i < n;i++)
    {
        if(!col[i] && !dg[v + i] && !udg[n - v + i])
        {
            g[v][i] = 'Q';
            col[i] = dg[v + i] = udg[n - v + i] = true;
            dfs(v + 1);
            col[i] = dg[v + i] = udg[n - v + i] = false;
            g[v][i] = '.';
        }
    }
}


int main()
{
    cin >> n;
    for(int i = 0;i < n;i++)
      for(int j = 0;j < n;j++)
        g[i][j] = '.';

    dfs(0);
    return 0;
}