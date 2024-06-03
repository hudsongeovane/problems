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
        vector<string> v(n);
        int firstline = -1;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            if (firstline == -1) for(int x = 0; x < v[i].length(); x++) {
                if (v[i][x] != '0') {
                    firstline = i;
                    break;
                }
            }
        }

        int total = 0;
        for(int k = 0; k < v[firstline].length(); k++) {
            if (v[firstline][k] == '1') {
                total++;
            }
        }

        firstline++;
        int total2 = 0;
        for(int k = 0; k < v[firstline].length(); k++) {
            if (v[firstline][k] == '1') {
                total2++;
            }
        }

        if (total == total2) cout << "SQUARE" << endl;
        else cout << "TRIANGLE" << endl;
    }
}