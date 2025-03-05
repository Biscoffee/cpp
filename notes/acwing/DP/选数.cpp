#include <iostream>
#include <vector>

using namespace std;

int n,k;
int cnt = 0;

bool isPrime (int x)
{
    if( x < 2) return false;
    for(int i = 2;i <= x / i;i++)
    {
        if(x % i == 0)  return false;
    }
    return true;
}

void dfs(int start, int k ,int sum,const vector <int>&a,int& cnt)
// k为还需选择的数的个数
{
    if(k == 0) {
        if(isPrime(sum))  cnt++;
        return;
    }
    for(int i = start;i < n ; i++)
    {
        dfs(i + 1,k - 1,sum + a[i], a , cnt);
    }
}

int main()
{
    cin >> n >> k;
    vector <int> a(n);
    for(int i = 0;i < n;i++)  cin >> a[i];
    dfs(0,k,0,a,cnt);
    cout << cnt << endl;
    return 0;


}