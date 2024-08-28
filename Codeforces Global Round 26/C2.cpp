#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int) 998244353};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE

const int SIZE = 2e5 + 5;

int a[SIZE]{};


void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];


    pair<int,int> dp[n + 1][2]{};
    dp[1][0] = {abs(a[1]), 1 + (a[1]>=0)};
    dp[1][1] = {a[1], (a[1]<0)};

    for (int i = 2; i <= n; i++) {
        int val1 = dp[i - 1][0].first + a[i];
        int val2 = abs(dp[i - 1][0].first + a[i]);
        int val3 = dp[i - 1][1].first + a[i];
        int val4 = abs(dp[i - 1][1].first + a[i]);

        int ans1 = max(max(val1, val2), max(val3, val4));
        dp[i][0].first = ans1; 

        if (val1 == ans1) dp[i][0].second = mod(dp[i][0].second + dp[i-1][0].second);
        if (val2 == ans1) dp[i][0].second = mod(dp[i][0].second + dp[i-1][0].second);
        if (val3 == ans1) dp[i][0].second = mod(dp[i][0].second + dp[i-1][1].second);
        if (val4 == ans1) dp[i][0].second = mod(dp[i][0].second + dp[i-1][1].second);

        // 

        val1 = dp[i - 1][0].first + a[i];
        val2 = abs(dp[i - 1][0].first + a[i]);
        val3 = dp[i - 1][1].first + a[i];
        val4 = abs(dp[i - 1][1].first + a[i]);

        int ans2 = min(min(val1, val2), min(val3, val4));
        dp[i][1].first = ans2;
        if (ans2 == ans1) continue;

        if (val1 == ans2) dp[i][1].second = mod(dp[i][1].second + dp[i-1][0].second);
        if (val2 == ans2) dp[i][1].second = mod(dp[i][1].second + dp[i-1][0].second);
        if (val3 == ans2) dp[i][1].second = mod(dp[i][1].second + dp[i-1][1].second);
        if (val4 == ans2) dp[i][1].second = mod(dp[i][1].second + dp[i-1][1].second);
    }

    int answer = 0;
    int ans = max(dp[n][0].first, dp[n][1].first);
    if (ans == dp[n][0].first) answer += dp[n][0].second;
    else if (ans == dp[n][1].first) answer += dp[n][1].second;
    cout << answer << endl;
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