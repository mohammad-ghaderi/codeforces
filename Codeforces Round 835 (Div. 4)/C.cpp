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
    int a[n];
    int mx1 = 0, mx2 = 0,idx1 = 0, idx2 = 0;
    for (int i = 0; i < n;  i++) {
        cin >> a[i];
        if (a[i] > mx1) {
            mx2 = mx1;
            idx2 = idx1;
            mx1 = a[i];
            idx1 = i;
        } else if (a[i] > mx2) {
            mx2 = a[i];
            idx2 = i;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == idx1) {
            cout << a[i] - a[idx2] << ' ';
        } else {
            cout << a[i] - a[idx1] << ' ';
        }
    }
    cout << endl;

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