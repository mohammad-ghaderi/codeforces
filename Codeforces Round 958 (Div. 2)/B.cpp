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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c0 = 0, c1 = 0;
    int last = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            c1++;
            last = 1;
        } else {
            if (last) c0++;
            last = 0;
        }
    }

    if (c1 > c0) cout << "YES\n";
    else cout << "NO\n";

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