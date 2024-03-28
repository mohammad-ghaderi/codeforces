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


void solve() {
    ll n, ans = 1;
    cin >> n;
    ll a[n], dp[n];
    vi p(100000, -1);
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317};

    FOR(i,0,n) cin >> a[i], dp[i] = 1;
    bool pr = false;
    FOR(i,0,n){
        pr = false;
        EACH(e, primes){
            if (e > a[i]) break;
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
    while (t--) solve();
    return 0;
}