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
        char suit;
        cin >> suit;
        cout << suit << endl;
        vector<string> v(2*n, "");
        string line;
        for (string &x: v) {
            cin >> x;
        }

        for(string a: v) {
            cout << a << " ";
        }
        cout << endl;
    }
}