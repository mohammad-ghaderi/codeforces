#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE



void solve() {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];

    int dp[n + 1][2]{};

    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(
            max(dp[i - 1][0] + a[i], abs(dp[i - 1][0] + a[i])),
            max(dp[i - 1][1] + a[i], abs(dp[i - 1][1] + a[i]))
        );
        dp[i][1] = min(
            min(dp[i - 1][0] + a[i], abs(dp[i - 1][0] + a[i])),
            min(dp[i - 1][1] + a[i], abs(dp[i - 1][1] + a[i]))
        );
    }

    cout << max(dp[n][0], dp[n][1]) << endl;
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