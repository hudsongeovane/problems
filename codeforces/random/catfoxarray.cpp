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

bool validate(v64 & a, ll k) {
    vector<int> v(20);
    forn(i, k) {
        ll el = a[i], st = 0;
        while (el > 0) {
            if (el%2 == 1) v[st]++;
            st++;
            el /= 2;
        }
    }

    forsn(i, k, a.size()) {
        ll el = a[i], st = 0;
        while (el > 0) {
            if (el%2 == 1) {
                if (v[st] == 0) return false;
                v[st]++;
            }
            st++;
            el /= 2;
        }
        el = a[i-k], st = 0;
        while (el > 0) {
            if (el%2 == 1) {
                v[st]--;
                if (v[st] == 0) return false;
            }
            st++;

            el /= 2;
        }
    }
    return true;
}

void solve(){
    ll n;
    cin >> n;
    v64 a(n);
    forn(i,n){
        cin >> a[i];
    }
    ll l=1,r=n, ans = n;
    while (l<=r){
        ll mid = (l+r)/2;
        if (validate(a,mid)) {
            ans = mid;
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    print(ans);
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