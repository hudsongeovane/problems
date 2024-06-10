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

bool IsBitSet(ll num, int bit)
{
    return 1 == ( (num >> bit) & 1);
}
ll countBits(ll number) 
{     
    return (ll)log2(number)+1; 
} 
ll dist(ll a, ll b) {
    if (a > b) swap(a,b);
    ll i = 0;
    while (a < b) {
        b /= 2;
        i++;
    }
    return i;
}
v64 transform(ll a, ll b) {
    v64 l, r;
    while (countBits(a) < countBits(b)) {
        r.pb(b);
        b /= 2;
    }
    while (countBits(a) > countBits(b)) {
        l.pb(a);
        a /= 2;
    }
    while (a!=b){
        l.pb(a);
        r.pb(b);
        a /= 2;
        b /= 2;
    }
    l.pb(a);
    reverse(all(r));
    for(ll i: r) {
        l.pb(i);
    }

    return l;
}

void solve(){
    ll n;
    cin >> n;
    vp64 v(n), q;
    forn(i, n) {
        cin >> v[i].fi;
        v[i].se = i;
        if (v[i].fi != -1) q.pb(v[i]);
    }
    list<ll> ans;
    if (q.size() == 0) {
        ll p = 1;
        forn(i, n) {
            cout << p << " ";
            if (i%2) p /= 2;
            else p *= 2;
        }
        cout << endl;
        return;
    }
    forn(i, n-1) {
        if (v[i].fi/2 != v[i+1].fi && v[i].fi != v[i+1].fi/2 && v[i].fi != -1 && v[i+1].fi != -1) {
            print(-1);
            return;
        }
    }
    bool doub = true;
    ll s = q[0].fi;
    for(ll i = q[0].se; i > 0; i--) {
        if (doub) s *= 2;
        else s /= 2;
        ans.push_front(s);
        doub = !doub;
    }
    for(ll i = 0; i < q.size()-1; i++) {
        if (q[i].se+1 == q[i+1].se) {
            continue;
        }
        v64 x = transform(q[i].fi, q[i+1].fi);
        ll spaces = q[i+1].se - (q[i].se+1);

        if (((ll)x.size())%1 != spaces%1 || spaces < (ll)x.size()-2) {
            print(-1);
            return;
        }
        doub = true;
        if (x.size() == 1) {
            while (spaces--) {
                if (q[i].fi > 1) ans.pb(doub ? q[i].fi/2 : q[i].fi);
                else ans.pb(doub ? q[i].fi*2 : q[i].fi);
                doub = !doub;
            }
        }
        else {
            for(ll j = 1; x[j] != q[i+1].fi; j++) {
                ans.pb(x[j]);
                spaces--;
            }
            while (spaces--) {
                if (x.back() > 1) ans.pb(doub ? x.back() : x.back()/2);
                else ans.pb(doub ? x.back() : x.back()*2);
                doub = !doub;
            }
        }
    }
    doub = true;
    for(ll i = q.back().se; i < n; i++) {
        if (doub) {
            if (q.back().fi > 1) ans.pb(q.back().fi/2);
            else ans.pb(q.back().fi*2);
        }
        else ans.pb(q.back().fi);
        doub = !doub;
    }
    auto it = ans.begin();
    forn(i, n) {
        if (v[i].fi == -1) {
            v[i].fi = *it;
            it++;
        }
    }
    forn(i, n-1) {
        if (v[i].fi/2 != v[i+1].fi && v[i].fi != v[i+1].fi/2) {
            print(-1);
            return;
        }
    }
    forn(i, n) {
        cout << v[i].fi << " ";
    }
    cout << endl;
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