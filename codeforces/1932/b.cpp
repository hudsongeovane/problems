#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int &i: v) {
            cin >> i;
        }

        int start = 0;
        for(int i = 0; i < v.size(); i++) {
            int c = v[i];
            if (c > start) {
                start = c;
            }
            else {
                start = ((start/c)+1) * c;
            }
        }
        cout << start << endl;
    }
}