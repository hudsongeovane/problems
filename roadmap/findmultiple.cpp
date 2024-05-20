#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (c >= a && c <= b) {
        cout << c << endl;
        return 0;
    }
    if (c > b) {
        cout << -1 << endl;
        return 0;
    }
    int d = a / c;
    if (a%c == 0) cout << a << endl;
    else if ((d+1)*c <= b) cout << (d+1)*c << endl;
    else cout << -1 << endl;
    return 0;
}