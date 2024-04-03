#include<bits/stdc++.h>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long int
#define pii pair<int,int>
#define vi vector<int>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORS(i, a, b, c) for (int i = a; i < b; i += c)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)
#define EACH(e, a) for (auto& e : a)
#define all(a) a.begin(), a.end();
#define F first
#define S second
#define endl "\n"

#define ONLINE_JUDGE

string n;
int m,d;
int MOD = 1e9 + 7;

int memo[2001][2][2001];
int dp(int index, bool last, int numb_mod) {

    if (index == n.size()) return numb_mod == 0;
    
    if (memo[index][last][numb_mod] != -1) return memo[index][last][numb_mod];

    int till = last ? n[index] - '0' : 9;
    int ans = 0;

    if (index % 2 == 1) {
        if (d <= till) ans = dp(index +1, last and (d == till), (numb_mod * 10 + d) % m);
    } else {
        FOR(digit, 0, till+1) {
            if (digit == d) continue;
            ans += dp(index +1, last and (digit == till), (numb_mod * 10 + digit) % m);
            ans %= MOD;
        }
    }
    return memo[index][last][numb_mod] = ans;
}


int f(string _n) {
    n = _n;
    memset(memo, -1, sizeof(memo));
    return dp(0,true,0);
}

void solve() {
    cin >> m >> d;
    string a,b;
    cin >> a;
    cin >> b;
    int i = a.size() - 1;
    while (i >= 0 and a[i] == '0') a[i--] = '9';
    a[i] -= 1;
    cout << (f(b) - f(a) + MOD)%MOD << endl;
}


int32_t main() {
    ghaderi
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
