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
 
ll get(v64 & v, ll idx) {
    if (idx < 0 || idx >= v.size()) return 0;
    return v[idx];
}
ll solvenaive(v64 & v, ll elements){
    ll maxsum = 0;
    for(ll i = 0; i < v.size(); i += elements) {
        ll sum = 0;
        for(ll j = 0; j < elements; j++) {
            sum += get(v, i+j);
        }
        maxsum = max(maxsum, sum);
    }
    return maxsum;
}

bool cansolve(v64 &v, ll maxsum, ll subs) {
    ll csum = 0;
    ll resets = 1;
    forn(i, v.size()) {
        if (csum + v[i] <= maxsum) {
            csum += v[i];
            continue;
        }
        resets++;
        --i;
        csum = 0;
    }
    return (resets <= subs);
}

int main()
{
    ll n,k;
    cin >> n >> k;
    v64 v(n);
    ll maxel = 0;
    forn(i, n) {
        cin >> v[i];
        maxel = max(maxel, v[i]);
    }

    ll l = maxel, r = solvenaive(v, ceil((ld)n/(ld)k));
    ll ans = r;
    while (l <= r) {
        ll mid = (l+r)/2;
        if (cansolve(v, mid, k)) {
            r = mid-1;
            ans = mid;
        }
        else {
            l = mid+1;
        }
    }
    cout << ans << endl;
}