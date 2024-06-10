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

v32 tobin(ll l, bool neg) {
    v32 res;
    while (l >= 1) {
        res.pb(neg ? (-1) * l%2 : l%2);
        l /= 2;
    }
    return res;
}
void solve(){
    // ll = inp()
    // v = 2
    // while (v < ll):
    //     v = v * 2
    
    // bina = tobin(ll, False)
    // inv = False
    // for i in range(len(bina)-1):
    //     if bina[i] and bina[i+1]:
    //         inv = True

    // res = bina
    // if inv:
    //     nbin = tobin(v - ll, True)
    //     res = nbin + tobin(v, False)[len(nbin):]
    // print(len(res))
    // for i in res:
    //     print(i, end=" ")
    // print("")
    ll x, v=2;
    cin >> x;
    while (v < x) {
        v *= 2;
    }
    v32 bina = tobin(x, 0);
    bool inv = 0;
    forn(i, bina.size()-1) {
        if (bina[i] && bina[i+1]) {
            inv = 1;
        }
    }
    v32 res = bina;
    if (inv) {
        v32 nbin = tobin(v-x, 1);
        res = nbin;
        v32 nov = tobin(v, 0);
        for(int i = nbin.size(); i < nov.size(); i++) {
            res.pb(nov[i]);
        }
    }
    cout << res.size() << endl;
    for(ll i: res) {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for(int it=0;it<t;it++) {
        solve();
    }
    return 0;
}