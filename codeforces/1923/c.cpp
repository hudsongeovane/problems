#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> c(n);
        for(int &i: c) {
            cin >> i;
        }
        int l, r;

        while (q--) {
            cin >> l >> r;
            map<int, int> cont;
            int maxel = 0;
            for(int i = l; i < r; i++) {
                if (cont.find(c[i-1]) != cont.end()) cont[c[i-1]] = 1;
                else {
                    cont[c[i-1]] += 1;
                }
                maxel = max(maxel, cont[c[i-1]]);
            }
            if (maxel > ((r-l+1)/2)) {
                cout << "no" << endl;
            }
            else {
                cout << "yes" << endl;
            }
        }
    }
}