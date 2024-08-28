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
    bool ans = true;
    if (n%10 == 9) ans = false;
    bool ez = false;

    while(n >= 10) {
        int nmb = n%10;
        nmb -= ez;
        ez = true;
        if (nmb < 0) {
            ans =false;
            break;
        }
        n /= 10;
    }

    if (n == 1 and ans) cout << "YES\n";
    else cout << "NO\n";
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