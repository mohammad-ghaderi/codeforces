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
    int n, k;
    cin >> n >> k;

    int a[k];

    for (int i = 0; i < k; i++) cin >> a[i];
    
    int mx = a[0];
    int idx = 0;
    for (int i = 0; i < k; i++) {
        if (a[i] > mx) mx = a[i], idx = i;
    }

    int sm = 0;
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        if (i == idx) continue;
        sm += (a[i] - 1);
        cnt += a[i];
    }

    cout << sm + cnt << endl;
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