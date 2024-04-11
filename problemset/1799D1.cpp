#include<bits/stdc++.h>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;

// #define ONLINE_JUDGE


ll n, k;
ll a[5005], cold[5005], hot[5005];
ll memo[5005][5005];

ll fnc(ll i, ll first, ll second) {
    // base case
    if (i == n) return 0;
    if (memo[i][second]>0) return memo[i][second];
    

    // recurrsive
    ll ans = 1e15;
    if (first == a[i]) ans = hot[a[i]] + fnc(i+1, first, second);
    else if (second == a[i]) ans = hot[a[i]] + fnc(i+1, second, first);
    else ans = cold[a[i]] + min(fnc(i+1, a[i], second), fnc(i+1, a[i], first));
    
    return memo[i][second] = ans;
}


void solve() {
    cin >> n >> k;
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 1; i <= k; i++) cin >> cold[i];
    for (ll i = 1; i <= k; i++) cin >> hot[i];
    for (ll i = 0; i <= n; i++) 
        for (ll j = 0; j < 5003; j++)
            memo[i][j] = 0;
    
    cout << fnc(0,5002, 5002) << '\n';
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
