#include<bits/stdc++.h>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;

ll n, m, x;
ll q[1000][2];
set<ll> ans{};
bool dp[1001][1001]{};

void dfs(ll i, ll new_x) {
    // base case
    if (new_x < 0) new_x = (n + new_x)%n;
    if (dp[i][new_x]) return;
    if (i == m) {
        if (new_x == 0) new_x = n;
        ans.insert(new_x); 
        return;
    }

    //recurrence base
    if (q[i][1] != 0) dfs(i+1, (new_x - q[i][0]) % n);
    if (q[i][1] != 1) dfs(i+1, (new_x + q[i][0]) % n);
    dp[i][new_x] = true;
}

void solve() {
    cin >> n >> m >> x;
    char c;
    for (ll i = 0; i < m; i++) cin >> q[i][0] >> c, q[i][1] = c - '0';
    for (size_t i = 0; i <= m; i++)
        for (size_t j = 0; j <= n; j++)
            dp[i][j] = false;

    dfs(0,x%n);
    cout << ans.size() << '\n';
    for (auto an: ans) cout << an << " ";
    cout << '\n';
    ans.clear();
}


int main() {
    // ghaderi
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
