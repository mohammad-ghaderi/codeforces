#include<bits/stdc++.h>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long
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

// #define ONLINE_JUDGE

void solve() {
    int n, x;
    cin >> n >> x;

    int ans = 0;
    
    for (int a = 1; a <= x - 2; a++) {
        for (int b = 1; b <= x - a - 1; b++) {
            if (a*b > n) break;
            int lim1 = (n - a*b) / (a+b);
            int lim2 = x - (a + b);
            int lim = min(lim1, lim2);

            ans += lim;
        }
    }

    cout << ans << endl;
}



int32_t main() {
    ghaderi
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}