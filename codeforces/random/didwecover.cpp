#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define print(x) cout << x << endl
#define contains(x,y) ((x).find(y) != (x).end())
#define llin(x) ll x; cin >> x


void solve(){
    ll n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    set<char> v;
    char last; ll start = 0, total = 0;
    stringstream cc;
    while (cc.str().length() != n) {
        v.clear();
        ll pos = -1;
        last = '-';
        forsn(i, start, m) {
            if (!contains(v, s[i])) {
                v.insert(s[i]);
                last = s[i];
                pos = i;
            }
        }
        if (v.size() != k) {
            break;
        }

        if (last != '-') {
            cc << last;
            start = pos+1;
        }
        if (start >= m) break;
    }
    if (cc.str().length() == n) { print("YES"); return; }
    bool no = false;
    v.clear();
    forsn(i, start, m) {
        v.insert(s[i]);
    }
    for(char i = 'a'; i < 'a'+k; i++) {
        if (!contains(v,i)) {
            no = true;
            while (cc.str().length() != n) cc << i;
            break;
        }
    }
    cout << (no ? "NO" : "YES") << endl;
    if (no) cout << cc.str() << endl;
}
int main()
{
    fast_cin();
    ll t=1;
    cin >> t;
    for(int it=0;it<t;it++) {
        solve();
    }
    return 0;
}