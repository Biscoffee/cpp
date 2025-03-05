#include <iostream>

using namespace std;

const int N = 25;

long long dp[N][N]; //路径数
bool st[N][N]; //

int n,m,hx,hy;

int dx[8] = {-2,-1,1,2,2,1,-1,-2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

int main()
{
    cin >> n >> m >> hx >> hy;
    st[hx][hy] = true;
    for(int k = 0;k < 8;k++)
    {
        int x = hx + dx[k],y = hy + dy[k];
        if(x >= 0 && y >= 0 && x <= n && y <= m)
        {
            st[x][y] = true;
        }
    }

    dp[0][0] = 1;

    for(int i = 0;i <= n;i++)
    {
        for(int j = 0;j <= m;j++)
        {
            if(st[i][j]){
                dp[i][j] = 0;
                continue;
            }
            if(i > 0)  dp[i][j] += dp[i - 1][j];
            if(j > 0)  dp[i][j] += dp[i][j - 1];
           
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}