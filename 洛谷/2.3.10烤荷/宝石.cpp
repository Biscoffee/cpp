#include <iostream>
#include <vector>
using namespace std;

long long minCandiesEaten(int n, int x, vector<int>& a) {
    long long total = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] + a[i + 1] > x) {
            int excess = a[i] + a[i + 1] - x;
            total += excess;
            a[i + 1] -= excess;
        }
    }
    return total;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << minCandiesEaten(n, x, a) << endl;
    return 0;
}