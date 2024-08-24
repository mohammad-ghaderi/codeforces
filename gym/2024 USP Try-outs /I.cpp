#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long 
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE

void solve() {
    int n;
    cin >> n;
    int a[n];

    bool z = true;
    bool one = true;
    bool even = true;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != 0) z = false;
        if (a[i] != 1 and a[i]!=0) one = false;
        if (a[i]&1) even = false;
    }

    if (z) cout << "0\n";
    else if (one or even) cout << "1\n";
    else cout << "2\n";


}


int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}