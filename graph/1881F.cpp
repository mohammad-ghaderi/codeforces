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
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE

const int mxN = 2e5+5; 

int n, k;
int g[mxN]{}, f[mxN]{};
bool a[mxN]{};
vector<int> e[mxN];


int dfs_g(int cur, int par) {
    int mx = a[cur] ? 0 : INT_MIN;

    for (auto x: e[cur]) {
        if (x == par) continue;
        int val = dfs_g(x, cur);
        if (val + 1 > mx) mx = val + 1;
    }

    return g[cur] = mx;
}

void dfs_f(int cur, int par, int par_dis) {
    int mx1 = INT_MIN, mx2 = INT_MIN;

    for (auto x: e[cur]) {
        if (x == par or g[x] < 0) continue;
        if (g[x] > mx1) {
            mx2 = mx1;
            mx1 = g[x];
        } else if (g[x] > mx2) {
            mx2 = g[x];
        }
    }

    for (auto x: e[cur]) {
        if (x == par) continue;

        int new_par_dis = par_dis;
        if (a[cur]) {
            new_par_dis = max(new_par_dis, -1);
        }
        if (g[x] != mx1) new_par_dis = max(new_par_dis, mx1);
        else new_par_dis = max(new_par_dis, mx2);

        dfs_f(x, cur, new_par_dis + 1);
    }

    f[cur] = max(g[cur], max(mx1, par_dis) + 1);
    
}


void solve() {
    cin >> n >> k;

    int t;
    memset(a, false, sizeof a);
    rep(i, 0, k) {
        cin >> t;
        a[t-1] = true;
    }

    int u, v;
    rep(i, 0, n-1) {
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs_g(0, -1);

    dfs_f(0, -1, INT_MIN);

    int ans = INT_MAX;
    rep(i, 0, n) {
        ans = min(ans, f[i]);
        e[i].clear();
    }

    cout << ans << endl;
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