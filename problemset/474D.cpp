// https://codeforces.com/problemset/problem/474/D
#include<bits/stdc++.h>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vii vector<pii>;
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

int t, k;
int a, b;
ll mem[100002];

void dp() {
    mem[0] = 1, mem[1] = 1;
    FOR(i, 1, 100002) {
        mem[i] = mem[i-1];
        if (i-k >= 0) mem[i] = MOD(mem[i] + mem[i-k]);
    }
    FOR(i,1,100002) mem[i] = MOD(mem[i] + mem[i-1]);
}


void solve() {
    cin >> t >> k;
    // memset(mem, 1, sizeof mem);
    dp();
    FOR(i,0,t) {
        cin >> a >> b;

        cout << MOD(mem[b] - mem[a-1]) << endl;
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
