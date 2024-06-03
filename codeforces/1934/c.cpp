#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <algorithm>

using namespace std;
#define LL long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector< pair<int, int> > calc;
        int n, m;
        cin >> n >> m;
        cout << "? 1 1" << endl;
        cout.flush();
        int p1, p2, p3, p4, p5, p6;
        int d;
        cin >> d;
        if (d == 0) {
            cout << "! 1 1" << endl;
            cout.flush();
            continue;
        }
        if (d < m) {
            p1 = 1;
            p2 = d+1;
        }
        else {
            p1 = d-m+2;
            p2 = m;
        }
        cout << "? " << p1 << " " << p2 << endl;
        
        int y = p2;
        for(int x = p1; x <= n; x++) {
            calc.push_back(make_pair(x, y));
            cout << x << y << endl;
            y--;
            if (y == 0) break;
        }

        int d1, d2, d3;
        cin >> d1;
        if (d1 == 0) {
            printf("! %d %d",p1,p2);
            cout << endl;
            cout.flush();
            continue;
        }

        if (d < n) {
            p3 = d+1;
            p4 = 1;
        }
        else {
            p3 = n;
            p4 = d-n+2;
        }
        cout << "? " << p3 << " " << p4 << endl;


        cin >> d2;
        if (d2 == 0) {
            printf("! %d %d",p3,p4);
            cout << endl;
            cout.flush();
            continue;
        }

        cout << "? 2 2" << endl;
        cin >> d3;
    }   
}