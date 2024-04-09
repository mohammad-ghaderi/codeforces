// https://codeforces.com/contest/35/problem/D

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

std::ifstream I("input.txt");
std::ofstream O("output.txt");

int n, x;
int a[100];
int mem[101][10001];
int dp(int index, int val) {
    // Base Case
    if (index == n) return 0;
    if (mem[index][val] != -1) return mem[index][val];

    // Recursive case
    int ans = dp(index + 1, val);
    if (a[index] <= val) ans = max(ans, dp(index + 1, val - a[index]) + 1);
    return mem[index][val] = ans;
}

void solve() {
    I >> n >> x;
    memset(a,0,sizeof a);
    memset(mem,-1,sizeof mem);
    FOR(i,0,n) I >> a[i],a[i]*=(n-i);
    O << dp(0,x);
}



int main() {
    ghaderi
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
