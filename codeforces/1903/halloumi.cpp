#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n, -1);

        cin >> v[0];
        int c = 1;
        bool impossible = false;
        for(int i = 1; i < n && !impossible; i++) {
            cin >> v[i];

            if (v[i] >= v[i-1]) {
                c = 1;
                continue;
            }
            else {
                c++;
                if (c > k) impossible = true;
            }
        }
        if (impossible) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
}