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

ll n, m, k;
ll getones(vv64 & psum, ll i, ll j) {
    return psum[i+k][j+k] - psum[i+k][j] - psum[i][j+k] + psum[i][j];
}

void solve(){
    cin >> n >> m >> k;
    vv64 a(n, v64(m));
    vector<vector<bool>> neve(n, vector<bool>(m, false));
    
    forn(i, n) {
        forn(j, m) {
            cin >> a[i][j];
        }
    }
    ll sum1 = 0, sum2 = 0;
    forn(i, n) {
        forn(j, m) {
            char x;
            cin >> x;
            if (x == '1') {
                neve[i][j] = true;
                sum1 += a[i][j];
            }
            else {
                neve[i][j] = false;
                sum2 += a[i][j];
            }
        }
    }
    if (k == 1 || sum1 == sum2){
        print("YES");
        return;
    }
    vv64 psum(n+1, v64(m+1,0));
    forsn(i, 1, n+1) {
        forsn(j, 1, m+1) {
            psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + neve[i-1][j-1];
        }
    }
    ll _gcd = -1;
    forn(i,n-k+1){
        forn(j,m-k+1) {
            ll ones = getones(psum,i,j), zeros = (k*k) - ones;
            if (ones != zeros) {
                if (_gcd == -1) _gcd = abs(zeros-ones);
                else _gcd = gcd(_gcd, abs(zeros-ones));
            }
        }
        // cout << endl;
    }
    if (_gcd == -1) print("NO");
    else if (abs(sum1-sum2)%_gcd == 0) print("YES");
    else print("NO");
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