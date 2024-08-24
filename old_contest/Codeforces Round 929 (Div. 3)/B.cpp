#include<iostream>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;


void solve() {
    int n, a;
    cin >> n;
    ll sm = 0;
    int fnd2 = 0;
    int fnd1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        sm += a;
        if (a%3 == 2) fnd2++;
        if (a%3 == 1) fnd1++;
    }
    int ans = 0;
    if (sm%3 == 1) {
        if (fnd1 > 0) ans = 1;
        else ans = 2;
        
    } else if (sm%3 == 2) {
        ans = 1;
    }
    cout << ans << '\n';
}

int main() {
    ghaderi
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}