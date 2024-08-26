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
    int a[n + 1];


    if (k%2 != 0) cout << "NO\n";
    else {
        for (int i = 1; i <= n; i++) a[i] = i;
        int f = 1, s = n;
        while(f < s and k > 0) {
            int diff = s - f;
            if (k >= 2*diff) {
                a[f] = s;
                a[s] = f;
                k -= 2*diff;
                s--;
                f++;
            } else f++;
        }

        if (k != 0) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) cout << a[i] << ' ';
            cout << endl;
        }
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