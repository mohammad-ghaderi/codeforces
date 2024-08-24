#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long 
#define endl "\n"



using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE


void solve() {
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    int i = n - 1;
    int sc = 0;

    while(i > 0) {
        int A = a[i];
        int B = a[i-1];
        
        int inc = min(k, A-B);
        B += inc;
        k -= inc;

        sc += (A - B);
        i -= 2;
    }

    if (i == 0) sc += a[0];

    cout << sc << endl;

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