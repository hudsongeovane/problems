#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        int cont = 1;
        while (k > (n+1)/2) {
            k = k - ((n+1)/2);
            n /= 2;
            cont *= 2;
        }
        cout << cont*(k*2 - 1) << endl;
    }
}