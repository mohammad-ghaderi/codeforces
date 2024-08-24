// https://codeforces.com/problemset/problem/1324/E

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
// #define _MOD (1000000007)
#define MOD(n,_MOD) (((n % _MOD) + _MOD) % _MOD)
// #define ONLINE_JUDGE
#define int int16_t

int n,h,l,r;
int a[2001]{};
int mem[2002][2002];

int dp(int i = 0, int time = 0) {
    // Base Case
    if (i == n) return 0;
    if (mem[i][time]!=-1) return mem[i][time];
    // Recursive case
    int ans1 = dp(i+1, MOD(time + a[i], h)) + (MOD(time + a[i], h) <= r and MOD(time + a[i], h) >= l);
    int ans2 = dp(i+1, MOD(time + a[i]-1, h)) + (MOD(time + a[i]-1, h) <= r and MOD(time + a[i]-1, h) >= l);
    return mem[i][time] = max(ans1,ans2);
}

void solve() {
    cin >> n >> h >> l >> r;
    FOR(i,0,n) cin >> a[i];
    memset(mem, -1, sizeof mem);
    cout << dp();

}



int32_t main() {
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
