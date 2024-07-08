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

bool dfs(vector<string> & s, int i, int j, set<p32> & v) {
    if (j == s[0].size()-1) return true;
    if (contains(v, mp(i,j))) return false;
    bool ans = false;
    v.insert(mp(i,j));
    if (s[i][j+1] == '>') {
        ans = ans || dfs(s,i,j+2,v);
    }
    if (j > 1) if (s[i][j-1] == '<') {
        ans = ans || dfs(s,i,j-2,v);
    }
    if (i == 0) {
        ans = ans || dfs(s,i+1, (s[i+1][j] == '<' ? j-1 : j+1), v);
    }
    else {
        ans = ans || dfs(s,i-1, (s[i-1][j] == '<' ? j-1 : j+1), v);
    }
    return ans;
}

void solve(){
    int n;
    cin>>n;
    vector<string> s(2);
    cin >> s[0];
    cin >> s[1];
    set<p32> visited;
    cout << (dfs(s,0,0,visited) ? "YES" : "NO") << endl;
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