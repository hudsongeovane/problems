#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define LL long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        LL n, bullets;
        cin >> n >> bullets;
        vector< pair<LL, LL> > monster(n, make_pair(0,0)); // pos > life
    
        for(int i = 0; i < n; i++) {
            cin >> monster[i].second;
        }
        for(int i = 0; i < n; i++) {
            cin >> monster[i].first;
            if (monster[i].first < 0) monster[i].first *= -1;
        }
        LL spent = 0;
        bool ans = false;
        sort(monster.begin(), monster.end());
        for(int i = 0; i < n; i++) {
            if (monster[i].first*bullets-spent < monster[i].second) {
                cout << "no" << endl;   
                ans = true;
                break;
            }
            spent += monster[i].second;
        }
        if (!ans) {
            cout << "yes" << endl;
        }
    }
}