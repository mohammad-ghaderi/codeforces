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

void solve() {
    ll n, m, c, t;
    cin >> n >> m;
    vector<pair<ll,ll>> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i].first;
    }

    for (ll i = 0; i < n; i++) {
        cin >> a[i].second;
    }

    sort(a.begin(), a.end());

    ll ans = 0;

    for (ll i = 0; i < n; i++) {
        // cout << "a[" << i << "]:(" << a[i].first << "," <<a[i].second<<") ";

        ll cnt1 = min(m/a[i].first, a[i].second);
        ans = max(ans, cnt1*a[i].first);
        // cout <<"h:" << ans << ' ';
        if (i<n-1 and a[i+1].first - a[i].first == 1) {
            ll rem = m - cnt1*a[i].first;
            ll cnt2 = min(rem/a[i+1].first, a[i+1].second);
            ans = max(ans, cnt1*a[i].first + cnt2*a[i+1].first);
            // cout <<"h:" << ans << ' ';
            ll cn = m - (cnt1*a[i].first + cnt2*a[i+1].first);
            cn = min(min(cn, cnt1), a[i+1].second - cnt2);
            ans = max(ans, cnt1*a[i].first + cnt2*a[i+1].first + cn);
            // cout <<"h:" << ans << ' ';
        }
            // cout << " - ";

              
    } 
    // cout << endl;

    cout << ans << endl;
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