#include <iostream>
#define LL long long
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        LL x;
        cin >> x;
        if (x%2 == 1) {
            cout << x/2 << " " << x/2 +1 << endl;
        }
        else {
            cout << -(x-1) << " " << x << endl;
        }
    }
}