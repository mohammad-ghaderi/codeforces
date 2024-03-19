#include<iostream>
#include<algorithm>
using namespace std;

#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    ll a[2*n]{};
    for (int i = 0; i < 2*n; i++) cin >> a[i];

    sort(a, a+2*n);
    ll sm = 0;
    for (int i = 0; i < n; i++) {
        sm += a[2*i];
    }
    cout << sm << endl;
}


int main() {
    ghaderi
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}