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
 
int main()
{
    ll n;
    cin >> n;
    vector<pair<pair<ll, ll>, ll>> v(n);

    vector<ll> ans(n);
    forn(i, n) {
        cin >> v[i].fi.fi >> v[i].fi.se;
        v[i].se = i;
    }
    sort(all(v));
    ll rooms = 0, last_room = 0;

    // pair: departure time, room
    priority_queue<pair<ll, ll>> pq;
    forn(i, n) {
        if (pq.empty()) {
            last_room++;
            pq.push(make_pair(-v[i].fi.se, last_room));
			ans[v[i].second] = last_room;
        }
        else {
            p64 minimum = pq.top();
            if (-minimum.fi < v[i].fi.fi) {
                pq.pop();
                pq.push(make_pair(-v[i].fi.se, minimum.se));
                ans[v[i].second] = minimum.se;
            }
            else {
                last_room++;
                pq.push(make_pair(-v[i].fi.se, last_room));
                ans[v[i].second] = last_room;
            }
        }
        rooms = max(rooms, (ll) pq.size());
    }
    cout << rooms << endl;
	for (int i = 0; i < n; i++) { cout << ans[i] << " "; }
    cout <<endl;
}
