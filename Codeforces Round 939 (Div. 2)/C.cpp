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
    int N;
    cin >> N;
    int n = N;
    int a[n + 1][n + 1]{};
    bool c = true;
    int m = 0;

    while(n) {
        for (int i = 1; i <= N; i++) {
            a[n][i] = i;
        }
        for (int i = 1; i <= N; i++) {
            a[i][n] = i;
        }
        n--;
    }

    int sm = 0;
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) sm += a[i][j];

    cout << sm << ' ' << 2*N << endl;


    c = true;
    n = N;


    while(n) {
        cout << "1 " << n << ' ';
        for (int i = 1; i <= N; i++) cout << i << ' ';
        cout << endl;
        cout << "2 " << n << ' ';
        for (int i = 1; i <= N; i++) cout << i << ' ';
        cout << endl;
        n--;
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