#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE



void solve() {
    int n, m;
    cin >> n >> m;
    string a[n], b[n];

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int row_a[n]{}, row_b[n]{}, col_a[m]{}, col_b[m]{};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            row_a[i] += a[i][j] - '0';
            row_a[i] %= 3;
            row_b[i] += b[i][j] - '0';
            row_b[i] %= 3;
            col_a[j] += a[i][j] - '0';
            col_a[j] %= 3;
            col_b[j] += b[i][j] - '0';
            col_b[j] %= 3;
        }
    }

    for (int i = 0; i < n; i++) {
        if (row_a[i] != row_b[i]) {
            cout << "NO\n";
            return;
        }
    }

    for (int j = 0; j < m; j++) {
        if (col_a[j] != col_b[j]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

}


int main() {
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