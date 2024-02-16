#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int s;
        cin >> s;
        vector<int> v(s, 0);
        for(int i = 0; i < s; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int sum = 0;
        for(int i = 1; i < s; i++) {
            sum += v[i] - v[i-1];
        }
        cout << sum << endl;
    }
}