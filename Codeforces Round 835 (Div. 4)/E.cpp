#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE



void solve() {
    int n;
    cin >> n;
    bool a[n];

    int zero_from_right[n]{};
    int one_from_left[n]{};
    int c = 0;
    for(int i = 0; i < n; i++) cin >> a[i], one_from_left[i] = c,c += (a[i] == 1);

    c = 0;
    for (int i = n-1; i >= 0; i--) zero_from_right[i] = c, c += (a[i] == 0);
    int ans = 0;

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] == 1) {
            ans += zero_from_right[i];
        }
    }

    int mx = 0;

    for (int i = 0; i < n; i++) {
        if (a[i]) {
            int an = one_from_left[i] - zero_from_right[i];
            mx = max(mx, an);
        } else {
            int an = zero_from_right[i] - one_from_left[i];
            mx = max(mx, an);
        }
    }

    cout << ans + mx << endl;

}


int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}