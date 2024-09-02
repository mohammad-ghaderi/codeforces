#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE
const int SIZE = 2e5+5;
int n, s, e;

vector<pair<int,int>> g[SIZE]{};
bool vis[SIZE]{};
set<int> an{};

void dfs_e(int u, int xr) {
    vis[u] = true;
    if (u != e) an.insert(xr);
    
    for (auto &[v, w]: g[u]) {
        if (!vis[v]) {
            dfs_e(v, xr ^ w);
        }
    }
}


bool dfs_s(int u, int xr) {
    vis[u] = true;
    if (u == e) return (xr == 0);
    if (an.find(xr) != an.end()) return true;

    for (auto &[v, w]: g[u]) {
        if (!vis[v]) {
            if (dfs_s(v, xr ^ w)) return true;
        }
    }
    
    return false;
}


void solve() {
    cin >> n >> s >> e;
    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i++) vis[i] = false;

    dfs_e(e, 0);

    for (int i = 1; i <= n; i++) vis[i] = false;

    if (dfs_s(s, 0)) cout << "YES\n";
    else cout << "NO\n";

    an.clear();
    for (int i = 1; i <= n; i++) g[i].clear();
}


int32_t main() {
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