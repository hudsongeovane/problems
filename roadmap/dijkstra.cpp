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

template <typename T, typename W>
class wenode { // weigted edge node
    public:
    vector<pair<ll, W>> adj;

    wenode() {};
};

template <typename T = ll, typename W = ll>
class wgraph {
    public:
    vector<wenode<T,W>> nodes;
    wgraph(ll n) {
        this->nodes.resize(n);
    }
    void add_edge(ll from, ll to, W weight) {
        this->nodes[from].adj.pb(mp(to, weight));
        this->nodes[to].adj.pb(mp(from, weight));
    }
};

// Stores dist, a vector of pairs, that indicates
// the minimum distance from source to vertex i and
// the vertex before i to achieve this minimum distance
template <typename T = ll, typename W = ll>
vp64 dijkstra(wgraph<T,W> & g, ll source) {
    priority_queue<p64, vector<p64>, greater<p64>> qu;
    qu.push(mp(0, source));
    vp64 dist(g.nodes.size(), mp(INF, -1));
    dist[0] = mp(0, -1);
    while (!qu.empty()) {
        ll ve = qu.top().se, weight = qu.top().fi;
        qu.pop();
        if (dist[ve].fi < weight) continue;
        for(auto l: g.nodes[ve].adj) {
            ll to = l.fi, pwe = l.se;
            if (weight+pwe < dist[to].fi) {
                dist[to].fi = weight+pwe;
                dist[to].se = ve;
                qu.push(mp(dist[to].fi, to));
            }
        }
    }
    return dist;
}



void solve(){
    ll n, m;
    cin >> n >> m;
    wgraph g(n);
    forn(i, m) {
        ll a,b,w;
        cin>>a>>b>>w;
        a--;
        b--;
        g.add_edge(a,b,w);
    }
    vp64 dist = dijkstra(g,0);
    if (dist[n-1].se == -1) {
        cout << -1 << endl;
        return;
    }
    
    stack<ll> st;
    st.push(n-1);
    ll pos = dist[n-1].se;
    while (pos != -1) {
        st.push(pos);
        pos = dist[pos].se;
    }
    while (!st.empty()) {
        cout << st.top()+1 << " ";
        st.pop();
    }
    cout << endl;
}
int main()
{
    fast_cin();
    ll t=1;
    // cin >> t;
    for(int it=0;it<t;it++) {
        solve();
    }
    return 0;
}