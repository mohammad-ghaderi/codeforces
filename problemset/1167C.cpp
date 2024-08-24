// https://codeforces.com/contest/1167/problem/C

#include<bits/stdc++.h>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
// #define int long long int
#define pii pair<int,int>
#define vi vector<int>
#define endl "\n"
#define _MOD (1000000007)
#define MOD(n) (((n % _MOD) + _MOD) % _MOD)
#define ONLINE_JUDGE

const int N = 5e5+1;

int n, m;
vector<int> gr[N];
bool vis[N]{}, vis_t[N]{};
int ans[N]{};


int dfs(int cur, int par) {
    vis[cur] = true;

    int numb = 1;
    for (auto nbr: gr[cur]) {
        if (nbr == par or vis[nbr] ) continue;
        numb += dfs(nbr, cur);
    }

    ans[cur] = numb;
    return numb;
}


void dfs_fill(int cur, int par) {
    vis_t[cur] = true;
    ans[cur] = ans[par];
    
    for (auto nbr: gr[cur]) {
        if (nbr == par or vis_t[nbr]) continue;
        dfs_fill(nbr, cur);
    }
}

void solve() {
    cin >> n >> m;

    int x, y, len;
    for (int i = 0; i < m; i++) {
        cin >> len;
        if (len == 0) continue;
        cin >> x;
        while (--len) {
            cin >> y;
            gr[x].push_back(y);
            gr[y].push_back(x);
            x = y;
        }
    }

    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ans[i] = dfs(i,0);
            dfs_fill(i,i);
        }
    }


    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}



int32_t main() {
    ghaderi
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
