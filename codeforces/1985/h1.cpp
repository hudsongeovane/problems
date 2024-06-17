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

ll n,m;
vector<vector<bool>> visited;
vector<vector<char>> s;
ll minc, maxc, minr, maxr, csize;


void dfs(ll a, ll b) {
    if (a < 0 || b < 0 || a >= n || b >= m) return;
    if (visited[a][b] || s[a][b] == '.') return;
    csize++;
    minr = min(minr, a);
    maxr = max(maxr, a);
    minc = min(minc, b);
    maxc = max(maxc, b);
    visited[a][b] = true;
    dfs(a+1,b);
    dfs(a-1,b);
    dfs(a,b+1);
    dfs(a,b-1);
}

void solve(){
    cin >> n >> m;
    visited = vector<vector<bool>> (n, vector<bool>(m,0));
    s = vector<vector<char>>(n, vector<char>(m, '.'));
    vector<int> freeR(n,0), freeC(m,0);

    vector<ll> R(n+10,0), L(m+10,0);
    forn(i, n) {
        forn(j,m){
            cin >> s[i][j];
            if (s[i][j] == '.'){
                freeR[i]++;
                freeC[j]++;
            }
        }
    }
    forn(i,n){
        forn(j,m) {
            if (s[i][j] == '#' && !visited[i][j]) {
                csize = 0;
                minc = minr = 10e7;
                maxc = maxr = -1;
                dfs(i,j);
                R[minr] += csize;
                R[maxr+3] -= csize;
                L[minc] += csize;
                L[maxc+3] -= csize;
            }
        }
    }
    ll mrow = 0, sum = R[0];
    forn(i, n) {
        sum += R[i+1];
        mrow = max(mrow, freeR[i] + sum);
    }
    sum = L[0];
    forn(i, m) {
        sum += L[i+1];
        mrow = max(mrow, freeC[i] + sum);
    }
    cout << mrow << endl;
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