#include<iostream>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;

void solve() {
    ll n, k, ans = -1;
    cin >> n >> k;
    ll mx_c = 2*n;
    ll d = k % 2 == 0 ? k/2 : (k+1) / 2;
    if (k<=4*n-4) {
        ans = d;
    } else  {
        if (k == 4*n-3) {
            ans = 2*n-1;
        } else {
            ans = 2*n;
        }
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