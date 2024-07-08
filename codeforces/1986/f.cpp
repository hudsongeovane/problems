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
#define print(x) cout << (x) << endl
#define contains(x,y) x.find(y) != x.end()
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


template <typename T>
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

ll dfstime = 0;
void tarjan(graph<ll> &g, ll st, v64 &disc, v64 &low, v64 &parent, vp64 & bridges) {
    disc[st] = low[st] = dfstime;
    ++dfstime;
    for(ll node: g.nodes[st].adj){
        if (disc[node] == INF) {
            parent[node] = st;
            tarjan(g, node, disc, low, parent, bridges);
            low[st] = min(low[st], low[node]);

            if (low[node] > disc[st]) {
                bridges.pb(mp(st,node));
            }
        }
        else if (node != parent[st]) {
            low[st]=min(low[st],disc[node]);
        }
    }
}
vp64 bridges(graph<ll> & g) {
    ll n = sz(g.nodes);
    v64 disc(n,INF), low(n,INF), parent(n,-1);
    vp64 bridges;
    tarjan(g,0,disc,low,parent,bridges);
    return bridges;
}

void dfs(graph<ll> & g, ll st, set<ll> &visited, v64 &sub) {
    visited.insert(st);
    ll x = visited.size();
    for(ll node: g.nodes[st].adj) {
        if (contains(visited, node)) continue;
        // if (mp(st,node) == avoid || mp(node,st) == avoid) continue;
        dfs(g, node, visited, sub);
    }
    sub[st] = visited.size() - x;
}

void solve(){
    dfstime = 0;
    ll n,m; cin >> n >> m;
    graph<ll> g(n);

    forn(i,m){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g.add_edge(a,b);
    }

    vp64 bds = bridges(g);
    if (bds.empty()) {
        print(n*(n-1)/2);
        return;
    }
    v64 sub(n, 0);
    set<ll> visited;
    dfs(g, 0, visited, sub);

    ll ans = INF;
    for(p64 el: bds) {
        ll p = 1+ min(sub[el.fi], sub[el.se]);
        ll q = n-p;
        ans = min(ans, p*(p-1)/2 + q*(q-1)/2);
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