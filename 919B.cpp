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

int k;
ll n = 9;
ll answer = 19;
bool fnd = false;

unordered_map<ll,ll> mem[11][10]{};
int dp(int index, ll number, int sum) {

    // Base case
    if (fnd) return 1;
    if (index == n) {
        if (sum != 10) return 0;
        if (--k == 0) answer = number, fnd = true;
        return 1;
    }
    auto iter = mem[index][sum].find(number);
    if (iter!=mem[index][sum].end()) return mem[index][sum][number];

    // Recursive case
    int ans = 0;
    FOR(digit,0,10) {
        if (sum + digit > 10 ) break;
        ans += dp(index+1, number * 10 + digit, sum + digit);
    }
    return mem[index][sum][number] = ans;
}



void solve() {
    cin >> k;
    dp(0,0,0);
    cout << answer;
       
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
