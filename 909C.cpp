// https://codeforces.com/problemset/problem/909/C/

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
bool a[5001]{};
ll mem[5001][5001]{};

ll dp(int index = 0, int depth = 0) {
    // Base Case
    if (depth < 0) return 0;
    if (index == n-1) return 1;
    if (mem[index][depth] != -1) return mem[index][depth];

    // Recursive case
    ll ans;
    if (a[index]) ans = dp(index+1, depth+1);
    else ans = MOD(dp(index, depth-1) + dp(index+1, depth));
    return mem[index][depth] = MOD(ans);
}


void solve() {
    cin >> n;
    char c;
    FOR(i,0,n) cin >> c, a[i] = (c == 'f');
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
