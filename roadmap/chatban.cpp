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
 

ll calc(ll k, ll messages) {
    if (messages <= k) {
        return (1+messages) * messages / 2;
    }
    return ((1+k)*k / 2) + (((k-1)+(k-(messages-k))) * (messages-k) / 2);
}
void solve(){
    ll k, x;
    cin >> k >> x;
    ll start = 2;
    ll end = 2*k-1;
    if (x == 1) {
        cout << 1 << endl;
        return;
    }
    if (x > calc(k, 2*k -1)) {
        cout << 2*k - 1 << endl;
    }
    while (start < end) {
        //cout << start << " " << end << endl;
        if (calc(k, start) >= x && calc(k, start-1) < x) {
            //cout << "--1 " << calc(k,start) << " " << calc(k,start-1) << endl;
            cout << start << endl;  
            return;
        }
        if (calc(k, end) >= x && calc(k, end-1) < x) {
            //cout << "--2 " << calc(k,end) << endl;
            cout << end << endl;
            return;
        }
        ll mid = (start + end)/2;
        if (calc(k, mid) >= x) {
            end = mid;
        }
        else {
            start = mid+1;
        }
    }
}
int main()
{
 fast_cin();
 ll t;
 cin >> t;
 for(int it=1;it<=t;it++) {
    solve();
 }
 return 0;
}