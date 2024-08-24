#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;


void solve() {
    int n;
    ll x, y;
    cin >> n >> x >> y;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    
    unordered_map<ll, unordered_map<ll,ll>> mod {};
    
    
    ll ans = 0;
    ll k,m,f;
    for (int i = 0; i < n; i++) {
        k = a[i]%x;
        m = a[i]%y;
        f = (x-k)%x;
        auto iter = mod[f].find(m);
        if (iter != end(mod[f])) ans += iter->second;
        iter = mod[k].find(m);
        if (iter != end(mod[k])) iter->second++;
        else mod[k][m] = 1;
    }
    cout << ans << endl;
}

int main() {
    ghaderi
    int t;
    cin >> t;
    while (t--) solve();

    return 0; 
}