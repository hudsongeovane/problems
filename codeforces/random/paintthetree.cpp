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
#define contains(x,y) (x.find(y) != x.end())

template <typename T>
class node {
    public:
    T data;
    vector<ll> adj;

    node(T data) {
        this->data = data;
    }
    node() {};
};


template <typename T = ll>
class graph {
    public:
    vector<node<T>> nodes;
    graph(ll n) {
        nodes.resize(n);
    }
    void add_edge(ll from, ll to) {
        nodes[from].adj.pb(to);
        nodes[to].adj.pb(from);
    }
};

// 
set<ll> visited;
ll mx = 0;
void dfs(graph<ll> & g, ll source, ll dist) {
    mx = max(mx, dist);
    visited.insert(source);
    for(ll v: g.nodes[source].adj) {
        if (!contains(visited, v)) dfs(g, v, dist+1);
    }
}

p64 mid(graph<ll> &g, ll source, ll b) {
    map<ll,ll> from;
    stack<p64> st;
    st.push(mp(source, 0));
    while (!st.empty()) {
        ll no = st.top().fi, dist = st.top().se;
        visited.insert(no);
        st.pop();
        if (no == b) {
            ll x = b;
            forn(i, (dist+1)/2){
                x = from[x];
            }
            return mp(x,dist);
        }
        for(ll v: g.nodes[no].adj) {
            if (!contains(visited,v)) {
                st.push(mp(v, dist+1));
                from[v] = no;
            }
        }
    }
    return mp(-1,-1);
}


void solve(){
    visited.clear();
    mx = 0;
    ll n;
    cin >> n;
    graph g(n);
    ll a, b;
    cin >> a >> b;
    --a; --b;
    forn(i, n-1) {
        ll x,y;
        cin >> x >> y;
        --x; --y;
        g.add_edge(x,y);
    }
    if (a == b){
        dfs(g, a, 0);
        cout << 2*(n-1) - mx << endl;
        return;
    }
    p64 m = mid(g,a,b);
    visited.clear();
    dfs(g,m.fi,0);
    cout << 2*(n-1)- mx + ((1+m.se)/2) << endl;
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