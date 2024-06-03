#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define LL long long

int abs(int a) {
    if (a < 0) return -1 * a;
    return a;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector< int > vp(n);
        for (int i = 0; i <n; i++) {
            cin >> vp[i];
            //vp[i].second = i;
        }
        sort(vp.rbegin(), vp.rend());
        cout << abs(vp[0] - vp[n-1]) + abs(vp[n-1] - vp[1]) + abs(vp[1] - vp[n-2]) + abs(vp[n-2] - vp[0]) << endl;
    }
}