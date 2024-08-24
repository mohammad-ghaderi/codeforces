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

const int SIZE = 2e5 + 5;
vector<int> e[SIZE]{};
int vis[SIZE]{};
bool in_cycle[SIZE]{}, vis_Marcel[SIZE]{}, vis_Valeriu[SIZE]{};
int pos[SIZE]{};
priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > q;

int cycle_ansistor = -1;

bool dfs_find_cycle(int cur, int par) {
    if (vis[cur] == 0) {
        vis[cur] = 1;
    } else if (vis[cur] == 1) {
        cycle_ansistor = cur;
        return true;
    } else {
        return false;
    }

    bool cycle = false;

    for (auto x: e[cur]) {
        if (x == par) continue;
        bool an = dfs_find_cycle(x, cur);
        if (an) in_cycle[x] = true;
        cycle |= an;
    }

    vis[cur] = 2;
    return cycle and cur != cycle_ansistor;
}


void bfs_Marcel(int cur) {
    q.push({0, cur});
    vis_Marcel[cur] = true;

    while (!q.empty()) {
        auto tp = q.top();
        q.pop();
        pos[tp.ss] = tp.ff;

        for (auto x: e[tp.ss]) {
            if (vis_Marcel[x]) continue;
            q.push({tp.ff + 1, x});
            vis_Marcel[x] = true;
        }
    }
}


bool bfs_Valeriu(int cur) {
    q.push({0, cur});
    vis_Valeriu[cur] = true;    

    while (!q.empty()) {
        auto tp = q.top();
        q.pop();
        if (in_cycle[tp.ss]) return pos[tp.ss] > tp.ff;
        pos[tp.ss] = tp.ff;

        for (auto x: e[tp.ss]) {
            if (vis_Valeriu[x]) continue;
            q.push({tp.ff + 1, x});
            vis_Valeriu[x] = true;
        }
    }

    return false;
}


void solve() {
    int n, a, b, u, v;
    cin >> n >> a >> b;

    rep(i, 0, n) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs_find_cycle(1, -1);

    bfs_Marcel(a);

    cout << (bfs_Valeriu(b)?"YES\n":"NO\n");

    rep(i, 0, n+1) {
        vis[i] = 0;
        e[i].clear();
        in_cycle[i] = false;
        vis_Marcel[i] = false;
        vis_Valeriu[i] = false;
        cycle_ansistor = -1;
    }
    while (!q.empty()) q.pop();
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