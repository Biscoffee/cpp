#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

int n;

int my_gcd(int a, int b) {
    return b == 0 ? a : my_gcd(b, a % b);
}

int lcm(int a, int b) {
    if (a == 0 || b == 0) {
        return 0; 
    }
   
    return abs(a * b) / std::gcd(a, b); 
}

int lcm(int a, int b, int c) {
    return lcm(lcm(a, b), c);
}

double S(int a,int b,int c){
    int ans1 = a * b * c;
    double ans2 = lcm(a,b,c)/ (lcm(a,b) * lcm(a,c) * lcm(b,c));
    double ans = (double) ans1 * ans2;
    return ans;
}

int main()
{ 
    int x,y,z;
    double result = 0;
    double max = 0;
    cin >> n;
    vector<int> a(n);
    
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n - 2;i++){
        for(int j = i + 1;j < n - 1;j++){
            for(int k = j + 1;k < n;k++){
                result = S(a[i],a[j],a[k]);
                if(result > max) {
                max = result;
                x = i;
                y = j;
                z = k;
                }
            }
        }
    }
    cout << a[x] << " " << a[y] << " " << a[z];
    return 0;
}


