#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

long long int n,x;


int main()
{
    cin >> n >> x;
    vector<long long int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    long long int cnt = 0;
    for(int i = 0;i < n - 1; i++){
        if(a[i] + a[i + 1] > x){
            cnt += a[i] + a[i + 1] - x;
            a[i + 1] -= a[i] + a[i + 1] - x;
        }
    }
    cout << cnt << endl;
    return 0;
}