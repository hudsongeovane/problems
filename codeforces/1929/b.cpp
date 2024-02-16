#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, d;
        cin >> l >> d;
        int pares = 2*l - 2;

        if (d <= pares*2) {
            cout << (d+1)/2 << endl;
        }
        else {
            int falta = d - pares*2;
            cout << falta + pares << endl;
        }
    }
}