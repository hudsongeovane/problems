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

p64 fullrep(vp64 & v, ll n, ll coins) {
    forn(i, v.size()) {
        if (v[i].fi >= n) continue;
        else coins -= n - v[i].fi;
        if (coins < 0) return mp(0,-1);
    }
    return mp(1, coins);
}
void solve(){
    ll n, k;
    cin>>n>>k;
    vp64 v(n);
    forn(i,n) {
        cin >> v[i].fi;
        v[i].se = i;
    }
    sort(all(v));
    ll l = 0, r = v.back().fi + k;
    ll ans = l, coinsleft;
    while (l <= r) {
        ll mid = (l+r)/2;
        p64 test = fullrep(v,mid,k);
        if (test.fi) {
            coinsleft = test.se;
            ans = mid;
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }
    ll higher = 0;
    for(ll i = v.size()-1; i >= 0; i--) {
        if (v[i].fi > ans) higher++;
    }
    cout << higher + coinsleft + ans*n - n + 1 << endl;
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