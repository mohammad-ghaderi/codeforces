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
    int p[n][2];
    int cnt0[n+1]{}, cnt1[n+1]{};
    
    for (int i = 0; i < n; i++) {
        cin >> p[i][0] >> p[i][1];
        if (p[i][1]) cnt1[p[i][0]]++;
        else cnt0[p[i][0]]++;
    }

    int c1 = 0, c2 = 0;
    for (int i = 0; i <= n; i++) {
        c1 += ((cnt0[i] && !cnt1[i]) or (!cnt0[i] && cnt1[i]));
        c2 += (cnt0[i] && cnt1[i]);
    }

    int z = 0;
    for (int i = 1; i < n; i++) {
        if (cnt1[i] && cnt0[i-1] && cnt0[i+1]) z++;
        if (cnt0[i] && cnt1[i-1] && cnt1[i+1]) z++;
    }

    int ans = z;

    ans += c2 * (n - 2);

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