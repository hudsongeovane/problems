#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int a, b;
        a = b = 0;
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == 'A') a++;
            else b++;
        }
        if (a > b) cout << 'A' << endl;
        else cout << 'B' << endl;
    }
}