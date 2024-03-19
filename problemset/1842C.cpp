#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    ll a[n];
    for (size_t i = 0; i < n; i++) cin >> a[i];
    unordered_map<ll,ll> b{};
    ll tabel[n+1]{};

    for (size_t i = 0; i < n; i++) {
        tabel[i+1] = tabel[i];
        auto iter = b.find(a[i]);
        if (iter == b.end()) {
            b[a[i]] = i;
            tabel[i+1] = tabel[i]; 
        } else {
           tabel[]
        }
    }
    cout << tabel[n] << endl;
}

int main() {
    ghaderi
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}