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
 

pair<bool, vp64> solvewith(multiset<ll> & numbers, ll sum, vp64 & ans) {
    if (numbers.empty()) return mp(true, ans);
    auto mmax = numbers.end();
    mmax--;
    ll vmmax = *mmax;


    if (numbers.find(sum - vmmax) == numbers.end()) return mp(false, ans);
    else {
        ll fill = sum-vmmax;
        numbers.erase(mmax);
        auto removealso = numbers.find(sum-vmmax);
        ll toremove = *removealso;
        if (removealso == numbers.end()) return mp(false, ans);
        numbers.erase(removealso);
        ans.pb(mp(vmmax, toremove));
        return solvewith(numbers, vmmax, ans);
    }
}
void solve(){
    int n;
    cin >> n;
    multiset<ll> numbers;
    forn(i, 2*n) {
        ll v;
        cin >> v;
        numbers.insert(v);
    }
    auto last = numbers.end();
    last--;
    for(auto it = numbers.begin(); it != numbers.end(); it++) {
        vp64 v;
        multiset<ll> cp = numbers;
        auto solved = solvewith(cp, *last + *it, v);
        if (solved.first) {
            cout << "YES" << endl;
            cout << *last + *it << endl;
            for(auto itt = solved.second.begin(); itt != solved.second.end(); itt++) {
                cout << itt->fi << " " << itt->se << endl;
            }
            return;
        }
        if (next(it) == prev(numbers.end())) break;
    }
    cout << "NO" << endl;
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
