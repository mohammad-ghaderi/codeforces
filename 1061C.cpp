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
// #define ONLINE_JUDGE

const ll MOD{(ll)1e9 + 7};
const ll N{(ll)1e6};

unordered_map<ll, vector<ll>> fact{};
void sieve(const ll n) {
    for (ll i{ 1 }; i <= n / 2; i++) {
        for (ll j{ i }; j <= n; j += i) fact[j].push_back(i);
    }
}


void solve() {
    int n;
    cin >> n;
    vll a(n);
    FOR(i, 0, n) cin >> a[i];
    vector<ll> mem(n + 1, 0);
    mem[0] = 1;
    
    FOR(i,0,n) {
        ll size = fact[a[i]].size();
        RFOR(j,size-1,0) {
            const ll pos = fact[a[i]][j];
            if (pos <= i + 1 and a[i] % pos == 0) mem[pos] = (mem[pos] + mem[pos - 1]) % MOD;
        }
    }
    
    ll ans{};
    FOR(i,1,n+1) ans = (ans + mem[i]) % MOD;
    cout << ans << '\n';;
}



int main() {
    ghaderi
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    sieve(N);
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
