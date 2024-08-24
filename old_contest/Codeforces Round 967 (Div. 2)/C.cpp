#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long 
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE
const int SIZE = 1001;
int n, x;

void solve() {
    cin >> n;

    vector<int> par(n + 1, 1);
    ll m =floor(log2(n));
    for (int j = 0; j < m+1; j++) {
        for (int i = 1; i <= n; i++) {
            cout << "? " << par[i] << ' ' << i << endl;
            cout.flush();
            cin >> x;
            par[i] = x;
        }
    }
    cout << "! ";
    for (int i = 2; i <= n; i++) cout << par[i] << ' ' << i << ' ';
    cout << endl;
    cout.flush();
}


int main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}