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
    int x, y, k;
    cin >> x >> y >> k;

    int cx = x / k;
    cx += (x%k!=0);

    int cy = y / k;
    cy += (y%k!=0);

    int z = 0;
    int mx = max(cx, cy);
    if (cx == cy) {
        cout << cx + cy << endl;
    } else {
        if (mx == cx) {
            cout << cx + cx - 1 << endl;
        } else cout << cy + cy << endl;
    }

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