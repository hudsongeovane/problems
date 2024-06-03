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
 

void solve(){
    ll n, m;
    cin >> n >> m;
    vv64 a(n, v64(m));
    vv64 b(n, v64(m));
    set< set<ll> > rowsa, colsa, rowsb, colsb;
    map<ll, p64> mm, mmb;

    forn(i, n) {
        forn(j, m) {
            cin >> a[i][j];
        }
        set<ll> q;
        q.insert(all(a[i]));
        rowsa.insert(q);
    }
    forn(i, n) {
        forn(j, m) {
            cin >> b[i][j];
        }
        set<ll> q;
        q.insert(all(b[i]));
        rowsb.insert(q);
    }
    forn(j, m) {
        v64 xa(m), xb(m);
        forn(i, n) {
            xa.push_back(a[i][j]);
            xb.push_back(b[i][j]);
        }
        set<ll> q, r;
        q.insert(all(xa));
        r.insert(all(xb));
        colsa.insert(q);
        colsb.insert(r);
    }
    if (rowsa != rowsb || colsa != colsb) {
        cout << "NO" << endl;
        return;
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