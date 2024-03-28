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

#define ONLINE_JUDGE



void solve() {
    ll n;
    cin >> n;
    ll a[n], b[n];
    FOR(i,0,n) cin >> a[i] >> b[i];
    ll dp[n][3]{};
    dp[0][0] = 0;dp[0][1] = b[0];dp[0][2] = 2*b[0];
    FOR(i,1,n) 
        FOR(j,0,3) 
            if (a[i] + j == a[i-1]+0) dp[i][j] = j*b[i] + min(dp[i-1][1],dp[i-1][2]);
            else if (a[i] + j == a[i-1]+1) dp[i][j] = j*b[i] + min(dp[i-1][0],dp[i-1][2]);
            else if (a[i] + j == a[i-1]+2) dp[i][j] = j*b[i] + min(dp[i-1][0],dp[i-1][1]);
            else dp[i][j] = j*b[i] + min(dp[i-1][0],min(dp[i-1][1], dp[i-1][2]));
        
    
    cout << min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2])) << endl;
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
