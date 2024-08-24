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

// #define ONLINE_JUDGE

int n, c, k;
string s;

int dp(int i, string p) {
    // Base Case
    if (i == n) return 0;
    if (i > n) return LONG_MAX;
    if (m > k) return LONG_MAX;


    // Recursive Case
    
    int ans = dp(i + 1, m + 1);
    if (m == k and ) 
    dp(i + m, 1);
}

void solve() {
    cin >> n >> c >> k;
    cin >> s;

}



int main() {
    ghaderi
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}