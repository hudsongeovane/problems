#include <bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T> void _do(T x){cerr<<x<<"\n";}
template<typename T,typename ...U> void _do(T x,U ...y){cerr<<x<<", ";_do(y...);}
#define dbg(...) cerr<<#__VA_ARGS__<<" = ";_do(__VA_ARGS__);

const int MOD1=1e9+7;
const int MOD2=998244353;
const ll INF=4e18;

ll fpow(ll a,ll b,ll m)
{
    if(!b) return 1;
    ll tmp=1;
    for(ll cur=a;b;b>>=1,cur=cur*cur%m) if(b&1) tmp=tmp*cur%m;
    return tmp;
}
ll inv(ll a,ll m) {return fpow(a,m-2,m);}

#define MottoHayaku ios::sync_with_stdio(false);cin.tie(0);
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define F first
#define S second
#define pb push_back
#define uni(c) c.resize(distance(c.begin(),unique(c.begin(),c.end())))
#define unisort(c) sort(c.begin(),c.end()),uni(c)

const int N=1e5+5;

int a[N],pos[N];

void solve()
{
    ll n;
    cin>>n;
    rep1(i,n)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }
    int mx=0,mn=n;
    set<int> s;
    bool can=1;
    rep1(i,n) if(a[i]!=i)
    {
        mx=i;
        mn=min(mn,a[i]);
        if(a[a[i]]!=i) can=0;
        else s.insert(a[i]+i);
    }
    if(mx==0)
    {
        ll tmp=n*2;
        cout<<tmp*(tmp+1)/2<<"\n";
        return;
    }

    ll ans=0;
    if(s.size()>1) can=0;
    if(can) ans++;// l==r
    {
        ans+=(n+mn-1+mx)*(n+mn-mx)/2;
    }
    if(n+mn+1<=n*2)
    {
        ans+=(n+mn)*(n*2-n-mn);
    }

    cout<<ans<<"\n";
}

signed main()
{
    MottoHayaku

    int t;
    cin>>t;
    //t=1;
    while(t--)
    {
        solve();
    }
}
