#include<iostream>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;


void solve() {
    ll left, right, ans = 0;
    cin >> left >> right;
    ll x = left, y = right, divisor = 10, dif;
    while (x > 0 or y > 0) {
        dif = (y % 10) - (x % 10);
        ll d = 1;
        while (d < divisor) {
            ans += d*dif;
            d = d * 10;
        }
        divisor *= 10;
        x/=10;y/=10;
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