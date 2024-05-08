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

const ll N{(ll)1e5};

int primes[N]{};
void sieve(const int n) {
    vector<bool> isP(sqrt(n), true);
    isP[0] = false;
    isP[1] = false;
    for (int i{ 2 }; i * i < n; i++) {
        if(isP[i]){
            for (int j{ 2 * i }; j * j < n; j += i){
                isP[j] = false;
            }
        }
    }

    ll j{};
    for(ll i{}; i * i < n; i++)
        if(isP[i]) primes[j++] = i;
}

void solve() {
    ll n, ans = 1;
    cin >> n;
    ll a[n], dp[n];
    int p[100000];
    memset(p, -1, sizeof p);
    FOR(i,0,n) cin >> a[i], dp[i] = 1;
    bool pr = false;
    FOR(i,0,n){
        pr = false;
        EACH(e, primes){
            if (e > a[i] or e == 0) break;
            if (a[i]%e==0 and a[i]!=e) {
                int other = a[i]/e;
                if (p[e]!=-1) dp[i] = max(dp[i], dp[p[e]]+1);
                if (p[other]!=-1 and other!=1 and other != e and other>317) dp[i] = max(dp[i], dp[p[other]]+1);
                p[e] = i;
                if (other!=1 and other>317) p[other] = i;
                ans = max(ans, dp[i]);
                pr = true;
            }
        }
        if (!pr) p[a[i]] = i;
    }

    cout << ans << endl;
}



int main() {
    ghaderi
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll t = 1;
    // cin >> t;
    sieve(100000);
    while (t--) solve();

    return 0;
}