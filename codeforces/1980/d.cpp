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
 

map<p64, ll> gg;

ll ggcd(ll a, ll b) {
    if (gg.find(mp(a,b)) == gg.end()) {
        ll r = gcd(a,b);
        gg[mp(a,b)] = r;
        gg[mp(b,a)] = r;
        return r;
    }
    return gg[mp(a,b)];
}
bool pass(v64 & a) {    
    forn(i, a.size() - 2) {
        if (gcd(a[i],a[i+1]) > gcd(a[i+1], a[i+2])) {
            return false;
        }
    }
    return true;
}
bool test(v64 a, ll idx) {
    a.erase(a.begin() + idx);
    return pass(a);
}

void solve(){
    ll n;
    cin >> n;
    v64 a(n);
    forn(i, n) {
        cin >> a[i];
    }
    ll dec = 0;
    forn(i, n-2) {
        if (gcd(a[i],a[i+1]) > gcd(a[i+1], a[i+2])) {
            if (test(a, i) || test(a, i+1) || test(a, i+2)) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
            return;
        }
    }
    cout << "YES" << endl;
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