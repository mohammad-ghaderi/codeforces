// https://codeforces.com/problemset/problem/245/H

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
#define _MOD (1000000007)
#define MOD(n) (((n % _MOD) + _MOD) % _MOD)
// #define ONLINE_JUDGE

string s;
int mem[5001][5001];
int dp(int i, int j) {
    // Base  case
    if (i < 0 or j == s.size()) return 0;
    if (s[i] != s[j]) return 0;
    if (~mem[i][j]) return mem[i][j];

    // Recursive case
    return mem[i][j] = dp(i-1, j+1) + 1;
}


void solve() {
    cin >> s;
    int n, l, r;
    memset(mem,-1,sizeof mem);
    FOR(i,0,n) {
        dp(i,i);
        dp(i,i+1);
    }

    cin >> n;
    FOR(i,0,n) {
        cin >> l >> r;
    }

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
