#include<iostream>
#include<climits>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    ll a[n], h[n];
    for (ll i{0}; i < n; i++) cin >> a[i] >> h[i];
    ll cnt = 0, last = -1;
    for (ll i = 0; i < n; i++) {
        if (last < 0 or a[i] - h[i] > last) last = a[i], cnt++;
        else if ((i == n-1) or (a[i] + h[i] < a[i+1])) last = a[i] + h[i], cnt++;
        else last = a[i];
    }
    cout << cnt << endl;
}

int main() {
    ghaderi
    // int tc;
    // cin >> tc;
    // while (tc) 
        solve();
    return 0;
}