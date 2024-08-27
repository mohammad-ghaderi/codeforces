#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE
const int inf = 1e18;


void solve() {
    int n, k;
    cin >> n >> k;
    int rep[n+ 1]{};
    for (int i = 1; i <= n; i++) cin >> rep[i];
    sort(rep + 1, rep + n + 1);
    int base = rep[1];

    int i;
    for (i = 2; i <= n; i++) {
        if (k == 0) break;
        int diff = rep[i] - rep[i - 1];
        if (k < diff * (i - 1)) break;
        k -= diff * (i - 1);
        base = rep[i];
    }

    if (i != n + 1) {
        if (k != 0) {
            int ech = k / (i - 1);
            k -= ech * ( i - 1);
            base+= ech;
        }
    } else {
        int ech = k / n;
        k -= ech * n;
        base += ech;
    }

    int mx = 0;
    for (int j = 1; j <= n; j++) {
        if (rep[j] > base) mx++;
    }

    int ans = base + (base - 1) * (n - 1);
    // cout << base << ' ' << ans << ' ';
    ans += k;
    ans += mx;


    cout << ans << endl;

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