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
#define contains(x,y) x.find(y) != x.end()

p64 sum(p64 &a, p64 b) {
    return mp(a.fi + b.fi, a.se + b.se);
}


void solve(){
    ll n;
    cin >> n;
    vp64 a(n);
    forn(i, n) {
        cin >> a[i].fi;
    }
    forn(i, n) {
        cin >> a[i].se;
    }
    p64 c = mp(0,0);
    ll m1 = 0, p1 = 0;
    forn(i, n) {
        p64 p = a[i];
        if (p.fi > p.se) {
            c = sum(c, mp(p.fi, 0));
        }
        else if (p.fi < p.se) {
            c = sum(c, mp(0, p.se));
        }
        else {
            if (p.fi == -1) m1++;
            if (p.fi == 1) p1++;
        }
    }
    while (m1--) {
        if (c.fi > c.se) c.fi--;
        else c.se--;
    }
    while (p1--) {
        if (c.fi < c.se) c.fi++;
        else c.se++;
    }
    cout << min(c.fi, c.se) << endl;
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