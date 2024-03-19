#include<bits/stdc++.h>
using namespace std;
#define ONLINE_JUDGE;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;



void solve() {
    ll n, k;
    cin >> n >> k;
    ll a[k], t[k];
    vector<ll> ans(n+1, 1e15);
    for (ll i = 0; i < k; i++) cin >> a[i];
    for (ll i = 0; i < k; i++) cin >> t[i], ans[a[i]] = t[i];


    for (ll i = 1; i <= n; i++) ans[i] = min(ans[i], ans[i-1]+1);
    for (ll i = n-1; i >= 0; i--) ans[i] = min(ans[i], ans[i+1]+1);
    
    for (ll i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << '\n';
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
