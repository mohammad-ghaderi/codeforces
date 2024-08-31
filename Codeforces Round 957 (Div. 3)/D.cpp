#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE
const int SIZE = 2e5 + 15;
const int inf = 1e7;

int n, m, k;
string s;

int mp[SIZE]{};

void solve() {
    cin >> n >> m >> k;
    cin >> s;
    s = "L" + s;

    for (int i = 0; i <= n+1; i++) mp[i] = inf;
    mp[0] = 0;
    for (int i = 0; i <= n; i++) {
        if (s[i] == 'C' or mp[i] > k) continue;
        for (int j = 1; j <= ((s[i]=='L' or i == 0)?m:1); j++) {
            if (i + j > n+1 or s[i + j] == 'C') continue;
            if (s[i + j] == 'W') {
                if (mp[i + j] > mp[i] + 1) mp[i + j] = mp[i] + 1;
            } else {
                if (mp[i + j] > mp[i]) mp[i + j] = mp[i];
            }
        }
    }

    if (mp[n+1] <= k) cout << "YES\n";
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