#include<bits/stdc++.h>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORS(i, a, b, c) for (int i = a; i < b; i += c)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)
#define EACH(e, a) for (auto& e : a)
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define endl "\n"

#define ONLINE_JUDGE

vi memo;

vi goods = {111111, 111110, 111101, 111100, 111011, 111010, 111001, 111000, 110111, 110110, 110101, 110100, 110011, 110010, 110001, 110000, 101111, 101110, 101101, 101100, 101011, 101010, 101001, 101000, 100111, 100110, 100101, 100100, 100011, 100010, 100001, 100000, 11111, 11110, 11101, 11100, 11011, 11010, 11001, 11000, 10111, 10110, 10101, 10100, 10011, 10010, 10001, 10000, 1111, 1110, 1101, 1100, 1011, 1010, 1001, 1000, 111, 110, 101, 100, 11, 10};

bool isvalid(int y) {
    while (y>0) {
        if (y%10 >1) return false;
        y/=10;
    }
    return true;
}

int dp(int x) {
    if (isvalid(x)) return 1;
    if (memo[x]!=-1) return memo[x];

    int ans = 0;
    EACH(e,goods) {
        if (x%e==0) ans = dp(x/e);
        if (ans == 1) return memo[x] = ans;
    }
    return memo[x] = ans;
}

void solve() {
    int n;
    cin >> n;
    memo.resize(n+5,-1);
    if (dp(n)==1) cout << "YES\n";
    else cout << "NO\n";
}



int main() {
    ghaderi
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
