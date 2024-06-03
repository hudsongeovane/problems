#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string l;
        cin >> l;
        int coins = 0;

        for(int i = 0; i < l.length(); i++) {
            if (i != l.length()-1) if (l[i] == '*' && l[i+1] == '*') break;
            if (l[i] == '@') coins++;
        }
        cout << coins << endl;
    }
}