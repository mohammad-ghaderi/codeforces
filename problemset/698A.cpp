// https://codeforces.com/problemset/problem/698/A
#include<bits/stdc++.h>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
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
int a[101];

enum {
    REST,
    CONTEST,
    SPORT,
};

int mem[101][3];
int dp(int index = 0, int last = REST) {
    // Base Case
    if (index == n) return 0;
    if (~mem[index][last]) return mem[index][last];

    // Recursive Case
    int ans = 105;
    if (a[index] == 0) {
        ans = min(ans, dp(index + 1, REST) + 1);
    } else if (a[index] == 1) {
        if (last != CONTEST) ans = min(ans, dp(index + 1, CONTEST));
        ans = min(ans, dp(index + 1, REST) + 1); 
    } else if (a[index] == 2) {
        if (last != SPORT) ans = min(ans, dp(index + 1, SPORT));
        ans = min(ans, dp(index + 1, REST) + 1);
    } else {
        if (last != CONTEST) ans = min(ans, dp(index + 1, CONTEST));
        if (last != SPORT) ans = min(ans, dp(index + 1, SPORT));
        ans = min(ans, dp(index + 1, REST) + 1);
    }
    return mem[index][last] = ans;
}


void solve() {
    cin >> n;
    FOR(i,0,n) cin >> a[i];
    memset(mem, -1, sizeof mem);
    cout << dp();

}



int main() {
    ghaderi
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
