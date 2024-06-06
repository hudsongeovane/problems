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

void solve(){
    ll n, m;
    cin >> n >> m;
    ll a[n][m];
    ll b[n][m];
    map<ll, p64> mm;
 
    forn(i, n) {
        forn(j, m) {
            cin >> a[i][j];
            mm[a[i][j]] = mp(i,j);
        }
    }
    forn(i, n) {
        forn(j, m) {
            cin >> b[i][j];
        }
    }
    forn(i, n) {
        ll rowi = mm[b[i][0]].fi;
        forn(j, m) {
            if (mm[b[i][j]].fi != rowi) {
                print("NO");
                return;
            }
        }
    }
    forn(j, m) {
        ll coli = mm[b[0][j]].se;
        forn(i, n) {
            if (mm[b[i][j]].se != coli) {
                print("NO");
                return;
            }
        }
    }
    print("YES");
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