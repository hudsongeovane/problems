#include <iostream>
using namespace std;
#define LL unsigned long long

LL inf = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    while (t--) {
        LL n, k;
        cin >> n >> k;
        LL pow = 1;
        LL result = 0;
        while (k > 0) {
            if ((k & 1) > 0) {
                result = (result + (pow % inf)) % inf;
            }
            k = k >> 1;
            pow = pow * n;
            pow %= inf;
        }
        cout << result << endl;
    }
}