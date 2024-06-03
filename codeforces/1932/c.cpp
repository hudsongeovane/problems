#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;
#define LL long long
#define MP make_pair
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<LL> v(n);
        for(LL &i: v) {
            cin >> i;
        }
 
        int l = 0, r = n-1;

        string s;
        cin >> s;
        int last;
        for(int i = 0; i < s.length(); i++) {
            if (l==r) {
                last = l;
            }
            if (s[i] == 'L') {
                l++;
            }
            else {
                r--;
            }
        }
        l = last;
        r = last;
        vector<LL> ans;
        LL res = v[last] % m;
        ans.push_back(res);

        for(int i = s.length()-2; i >= 0; i--) {
            if (s[i] == 'L') {
                l--;
                res = (res * v[l]) % m;
            }
            else {
                r++;
                res = (res * v[r]) % m;
            }
            ans.push_back(res);
        }
        for(int i = ans.size()-1; i >= 0; i--) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}