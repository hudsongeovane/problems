#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define LL long long


LL solve(vector<LL> &v, int start, int level, bool contleft, bool contright) {
    if (start < 0 || start >= v.size()) return -1;

    if (start > 0 && v[start]+v[start-1] >= level) {
        return 1;
    }
    if (start < n-1 && v[start]+v[start+1] >= level) {
        return 1;
    }
    if (contleft && start>0) {
        LL left = solve(v, start-1, 
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<LL> v(n);
        for(LL &i: v) {
            cin >> i;
        }
        for(int i = 0; i < n; i++) {
            cout << solve(v, i, v[i]+1);
        }
    }
}