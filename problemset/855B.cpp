// https://codeforces.com/problemset/problem/855/B

#include<bits/stdc++.h>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long int
#define pii pair<int,int>
#define vi vector<int>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORS(i, a, b, c) for (int i = a; i < b; i += c)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)
#define EACH(e, a) for (auto& e : a)
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define endl "\n"
#define _MOD (1000000007)
#define MOD(n) (((n % _MOD) + _MOD) % _MOD)
// #define ONLINE_JUDGE

int n;
int m[3]{};
vi a;
vector<vector<int>> mem;

int dp(int index = 0, int value = 2) {
    // Base case
    if (value == -1) return 0;
    if (index == n) return -4e18;
    if (mem[index][value]!= -4e18) return mem[index][value];

    // Recursive case
    
    int ans = dp(index , value - 1) + (m[value] * a[index]);
    ans = max(ans, dp(index + 1, value));
    
    
    return mem[index][value] = ans;
}

void solve() {
    cin >> n >> m[2] >> m[1] >> m[0];
    a.resize(n);
    FOR(i,0,n) cin >> a[i];
    mem.resize(n, vector<int>(3, -4e18));
    cout << dp();
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
