#include<iostream>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;


void solve() {
    int n, a;
    cin >> n;
    ll sm = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        sm += abs(a);
    }
    cout << sm << '\n';
}

int main() {
    ghaderi
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}