#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    int minV = 1, maxV = 1e9;
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        int lower = ceil((double)A / (B + 1));
        int upper = A / B;
        minV = max(minV, lower);
        maxV = min(maxV, upper);
    }

    cout << minV << " " << maxV << endl;

    return 0;
}