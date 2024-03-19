#include<iostream>
#include<climits>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef unsigned long long ull;
const ull MOD = 1e9+7;

void solve() {
    ull n;
    cin >> n;
    ull normal_bef = 1, ans = 0, temp;
    for (ull i = 1; i < n; i++) {
        temp = 2 * normal_bef + ans;
        ans = 3 * normal_bef % MOD;
        normal_bef = temp % MOD;
    }
    cout << ans;
}

int main() {
    ghaderi
    // int tc;
    // cin >> tc;
    // while (tc) 
        solve();
    return 0;
}