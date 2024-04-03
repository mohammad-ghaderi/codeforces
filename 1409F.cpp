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

int n, k;
string s;
string t;
int nxt_cnt[201];

ll memo[201][201][201];
ll dp(int index, int first, int _k) {

    // Base Case
    if (index == s.size()) return 0;
    if (memo[index][first][_k]!=-1) return memo[index][first][_k];

    // Recursive
    ll ans = 0, an = 0;

    // leave
    an = dp(index +1, first + (s[index] == t[0]), _k);
    if (s[index]==t[0]) an += nxt_cnt[index+1];
    ans = max(ans, an);

    if (_k>0) {
        // replace with first
        an = 0;
        if (s[index]!=t[0]) {
            an = dp(index+1, first + 1, _k-1);
            an += nxt_cnt[index+1];
            if (s[index]==t[1]) an -= first;
            if (t[0]==t[1]) an += first;
        }
        ans = max(ans, an);
        
        // replace with second
        an = 0;
        if (s[index]!=t[1]) {
            an = dp(index+1, first, _k-1);
            an += first;
            if (t[0]==t[1]) an += nxt_cnt[index+1];
        }
        ans = max(ans, an);
    }
    return memo[index][first][_k] = ans;
}

void solve() {
    cin >> n >> k;
    cin >> s;
    cin >> t;
    memset(nxt_cnt,0,sizeof(nxt_cnt));
    RFOR(i,n-1,0) nxt_cnt[i] = nxt_cnt[i+1] + (s[i] == t[1]);
    memset(memo,-1,sizeof(memo));
    cout << dp(0, 0, k);

}



int main() {
    ghaderi
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
