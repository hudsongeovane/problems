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
}
int main()
{
    fast_cin();
    ll n, k, x;
    cin >> n >> k >> x;
    v64 v(n);
    ll totalsum = 0;
    forn(i, n) {
        cin >> v[i];
        totalsum += v[i];
    }
    if (k == 0) {
        cout << totalsum << endl;
        return 0;
    }
    sort(rall(v));
    forn(i, n) {
        if (v[i] > x) {
            ll use_coupon = v[i]/x;
            if (use_coupon <= k) {
                v[i] -= use_coupon * x;
                totalsum -= x * use_coupon;
                k -= use_coupon;
            }
            else {
                v[i] -= x * k;
                totalsum -= x * k;
                k = 0;
                cout << totalsum << endl;
                return 0;
            }
        }
    }
    sort(rall(v));
    forn(i, n) {
        if (k) {
            totalsum -= v[i];
            v[i] = 0;
            k--;
        }
        if (!k) break;
    }
    cout << totalsum << endl;
    return 0;
}