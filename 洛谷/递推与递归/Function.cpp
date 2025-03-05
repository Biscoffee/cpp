#include <iostream>
#include <cstring>

using namespace std;

long long dp[21][21][21];

long long w(int a,int b,int c)
{
    if(dp[a][b][c] != -1) return dp[a][b][c];
    if(a <= 0 || b <= 0 || c <= 0)  return 1;
    if(a > 20 || b > 20 || c > 20) return w(20,20,20);

    if(a < b && b < c) {
        dp[a][b][c] = w(a,b,c - 1) + w(a,b - 1,c - 1) - w(a,b - 1,c);
    } else {
        dp[a][b][c] = w(a - 1,b,c) + w(a - 1,b - 1,c) + w(a - 1,b,c - 1) - w(a - 1,b - 1,c - 1);
    }

    return dp[a][b][c];
}

int main()
{
    memset(dp,-1,sizeof dp);

    int a,b,c;
    while(cin >> a >> b >> c)
    {
        if(a == -1 && b == -1 && c == -1)  break;
        long long ans = w(a,b,c);
        cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << endl;
    }
    return 0;
}