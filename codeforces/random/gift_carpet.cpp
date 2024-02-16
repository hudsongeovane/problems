#include <iostream>
#include <set>
#include <string>
#include <vector>


using namespace std;

vector<string> a;

int main() {
    int testcases;
    cin >> testcases;
    while (testcases) {
        a.clear();
        testcases--;
        int n, m;
        cin >> n >> m;
        string line;
        for(int i = 0; i < n; i++) {
            cin >> line;
            a.push_back(line);
        }

        string to_find = "vika";
        int start = 0;
        bool found = false;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (a[j][i] == to_find[start]) {
                    start++;
                    if (start == 4) {
                        found = true;
                    }
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        cout << (found ? "YES" : "NO") << endl;
    }
}