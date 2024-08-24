#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long 
#define ld long double
#define vll vector<ll>
#define vv vector<vll>
#define pb push_back
#define lb lower_bound2
#define ub upper_bound
#define pll pair<ll,ll>
#define vpll vector<pll>
#define ff first
#define ss second
#define tll tuple<ll,ll,ll>
#define vtll vector<tll> 
#define mt make_tuple
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define each(e, a) for (auto& e : a)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define vect(a,n) vll a(n); rep(i,0,n) cin>>a[i];
#define all(a) a.begin(),a.end()
#define sortall(a) sort(a.begin(),a.end());
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"


//Debug
#define printv(a) rep(i,0,a.size()) cout<<a[i]<<" "; cout<<endl;
#define pout(p) cout<<"("<<p.ff<<","<<p.ss<<")"<<" ";
#define printvp(a) rep(i,0,a.size()) cout<<"("<<a[i].ff<<","<<a[i].ss<<")"<<" "; cout<<endl;
#define tout(t) cout<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")"<<endl;
#define trace(x) cout<< '>' << #x << ':' << (x) << "\n";
#define trace2(x,y) cout<< '>' << #x << ':' << (x) << " | " << #y << ':' << (y) << "\n";
#define trace3(a,b,c) cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n";
#define trace4(a,b,c,d) cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n";


using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m;}

// #define ONLINE_JUDGE

const int mxN = 1005; 
ll dist[mxN][mxN], slow[mxN];
vector<pair<ll,ll>> l[mxN];
int n, m;

priority_queue< pair<ll, int>, vector< pair<ll, int> >, greater< pair<ll, int> > > q;

void dijkstra(int s){
    q.push({0LL, s});
    for (int i = 0; i < n; ++i)
        dist[s][i] = 1e15;
    dist[s][s] = 0LL;

    while (q.size()){
        pair<ll, int> u = q.top();
        q.pop();
        if (u.first != dist[s][u.second])
            continue;

        for (const pair<int, ll>& x : l[u.second]){
            if (u.first + x.second < dist[s][x.first]){
                dist[s][x.first] = u.first + x.second;
                q.push({dist[s][x.first], x.first});
            }
        }
    }
}


void solve() {
    cin >> n >> m;
    
    int v, u, w;
    rep(i, 0, m) {
        cin >> u >> v >> w;
        v--;u--;
        l[u].push_back({v,w});
        l[v].push_back({u,w});
    }

    rep(i, 0, n) cin >> slow[i];

    rep(i, 0, n) dijkstra(i);

    rep(i, 0, n) l[i].clear();

    rep(i, 0, n) {
        rep(j, 0, n) {
            if (i == j) continue;
            ll val = dist[i][j] * slow[i];
            l[i].push_back({j,val});
        }
    }

    dijkstra(0);

    cout << dist[0][n-1] << endl;


    for (int i = 0; i < n; i++)
        l[i].clear();

}


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}