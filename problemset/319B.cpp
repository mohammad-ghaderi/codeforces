#include<bits/stdc++.h>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;
#define ONLINE_JUDGE

ll n,m,x;
vector<ll> a;

bool fnc() {
    unordered_set<ll> s{}, st{};

    for (ll i = 0; i < n; i++) {

        for (auto y: s) {
            x = (y+a[i]%m)%m;
            if (x == 0) return true;
            st.insert(x);
        }
        s.insert(a[i]%m);
        if (a[i]%m == 0) return true;
        for (auto y: st) s.insert(y);
        st.clear();
    }
    return false;
}

void solve() {
    cin >> n >> m;
    a.resize(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    if (fnc()) cout << "YES";
    else cout << "NO";
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
