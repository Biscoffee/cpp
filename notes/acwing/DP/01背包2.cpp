#include <iostream>
#include <cstring>

using namespace std;

int n,m;
int v[1010],w[1010];
int f[1010];
int main()
{
    cin >> n >> m;

    for(int i = 0;i < n;i++)  cin >> v[i] >> w[i];
    for(int i = 1;i <= n;i ++)
    {
        for(int j = m;j  >= v[i];j --)
            f[j] =max(f[j],f[j - v[i]] + w[i]);
    }
    cout << f[m] << endl;
    return 0;
}