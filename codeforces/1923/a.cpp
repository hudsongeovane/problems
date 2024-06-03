#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        int first = 9999;
        int last = -1;
        int ones = 0;
        for(int i = 0; i < v.size(); i++) {
            cin >> v[i];
            if (v[i] == 1) {
                first = min(first, i);
                last = max(last, i);
                ones++;
            }
        }
        cout << last-first-ones + 1 << endl;
    }
}

        