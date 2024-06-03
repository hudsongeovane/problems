#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
#define LL long long


set<LL> higher(set<LL> &a, set<LL> &b) {
    if (lexicographical_compare(a.rbegin(), a.rend(), b.rbegin(), b.rend())){
        return b;
    }
    return a;
}

set<LL> solve(vector<LL> & v) {
    if (v.size() == 0) {
        return set<LL>();
    }

    // selecionando v[0]
    set<LL> ms;
    ms.insert(v[0]);
    vector<LL> nv = {v.begin()+1, v.end()};
    
    for(int i = 0; i < nv.size(); i++) {
        nv[i]--;
    }

    set<LL> resto = solve(nv);
    resto.insert(v[0]);

    
    //nao selecionando v[0]

    vector<LL> nv2 = {v.begin()+1, v.end()};
    set<LL> resto2 = solve(nv2);
    resto2.insert(v[0]);

    return higher(resto, resto2);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<LL> v(n, 0);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            v[i] += i+1;
        }
        set<LL> s = solve(v);
        for(set<LL>::reverse_iterator it = s.rbegin(); it != s.rend(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
}