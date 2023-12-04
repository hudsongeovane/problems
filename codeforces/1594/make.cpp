#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a;
        char l;
        cin >> a >> l;
        string s;
        cin >> s;

        string finish(a, l);
        set<int> numbers;

        bool found = false;
        if (s.compare(finish) == 0) {
            cout << 0 << endl;
            continue;
        }
        else {
            for(int i = a/2; i < a; i++) {
                if (s[i] == l) { cout << 1 << endl << i+1 << endl; found = true; break; }
            }
        }

        if (!found) cout << 2 << endl << s.length() << " " << s.length()-1 << endl;
    }
}