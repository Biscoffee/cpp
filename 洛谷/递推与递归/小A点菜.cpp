#include <iostream>
#include <vector>
using namespace std;

const int N = 110;

int n,m;
int dp[N];
int main()
{
    cin >> n >> m;
    vector<int> a(n,0);
    dp[0] = 1;
    for(int i = 0;i < n;i++)  cin >> a[i];
    for(int i = 0;i < n;i++)
    {
        for(int j = m;j >= a[i];j--)
            dp[j] = dp[j] + dp[j - a[i]];
    } 
    cout << dp[m] << endl;
}