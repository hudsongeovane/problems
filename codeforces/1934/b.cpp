#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <algorithm>

using namespace std;
#define LL long long


map< LL, LL > mymap;

LL calc(LL v) {
    if (v < 0) return 99999999;
    if (v == 1) return 1;
    if (v == 3) return 1;
    if (v == 6) return 1;
    if (v == 10) return 1;
    if (v%15 == 0) return v/15;
    if (mymap.find(v) != mymap.end()) return mymap[v];
    LL res = min(1+calc(v-1), min(1+calc(v-3), min(1 + calc(v-6), min(1+calc(v-10), 1+ calc(v-15)))));
    mymap[v] = res;
    return res;
}


int main() {
    int t;
    cin >> t;
    for(int i = 1; i < 50; i++) {
        calc(i);
    }
    while (t--) {
        LL v;
        cin >> v;
        cout << min((v/15) + calc(v%15), (v-10)/15 + calc((v-10) %15) + 1)  << endl;
    }
}