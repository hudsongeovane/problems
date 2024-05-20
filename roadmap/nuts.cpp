#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t < 10) continue;
        else sum += t - 10;
    }
    cout << sum << endl;
}
