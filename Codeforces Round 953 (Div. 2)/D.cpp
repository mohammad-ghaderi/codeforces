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
    int n, c;
    cin >> n >> c;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int mx = 0;
    int val = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > val) mx = i, val = a[i];
    }

    int back = 0, fir = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        
        if (i == 0) {
            int sm = a[i] + c;
            cout << (i + (sm < val)) << ' ';
            back = sm;
            fir = sm;
            continue;
        }

        if (i == mx) {
            if (fir < a[i]) cout << "0 ";
            else cout << i << ' ';
            
        } else {
            if ( i > mx or a[i] + back > val or (a[i] + back == val and i < mx)) cout << i << " ";
            else cout << i + 1 << ' ';
        }
        back += a[i];
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