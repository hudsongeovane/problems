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

ll n,m;

ll get(vv64 &a, ll i, ll j) {
    if (i < 0 || j < 0 || i >= n || j >= m) {
        return -1;
    }
    return a[i][j];
}
bool ok(vv64 &a) {
    forn(i,n) {
        forn(j, m) {
            ll x = get(a,i,j);
            if (x > get(a,i+1,j) && x > get(a,i-1,j) && x > get(a,i,j+1) && x > get(a,i,j-1)) {
                a[i][j] = max(get(a,i+1,j), max(get(a,i-1,j), max(get(a,i,j+1),  get(a,i,j-1))));
                return true;
            }
        }
    }
    return false;
}

void solve(){
    cin >> n >> m;
    vv64 a(n, v64(m));
    forn(i,n){
        forn(j,m){
            cin >> a[i][j];
        }
    }
    while (ok(a)) {
        continue;
    }
    forn(i, n) {
        forn(j, m) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

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