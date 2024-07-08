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
#define read_ll_v64(x,y) llin(x); v64 y(x); forn(_, x) cin >> y[_];


void solve(){
    read_ll_v64(n, a);
    v64 psum(n), ideal(n);
    psum[0]=a[0];
    ideal[0]=1;
    ll mn = (psum[0] == ideal[0]);
    forsn(i,1,n){
        psum[i] = a[i] + psum[i-1];
        ideal[i] = ideal[i-1] + i + 1;
        if (ideal[i] == psum[i]) mn++;
    }
    ll count = 0, mx = 0, mxmx = 0;
    v64 even, odd;
    for(ll i = 0; i < n-1; i += 2) {
        if (ideal[i] != psum[i]) {
            if (psum[i] - a[i] + a[i+1] == ideal[i]) {
                even.pb(i);
            }
        }
        else {
            even.pb(-1);
        }
    }
    mx = count = 0;
    for(ll i = 1; i < n-1; i += 2) {
        if (ideal[i] != psum[i]) {
            if (psum[i] - a[i] + a[i+1] == ideal[i]) {
                odd.pb(i);
            }
        }
        else {
            odd.pb(-1);
        }
    }

    forn(i, sz(even)) {
        if (even[i] >= 0) count++;
        else count--;
        mxmx = max(mxmx, count);
        if (count < 0) count = 0;
        
    }
    count = 0;
    forn(i, sz(odd)) {
        if (odd[i] >= 0) count++;
        else count--;
        if (count < 0) count = 0;
        mxmx = max(mxmx, count);
    }
    print(mn + mxmx);
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