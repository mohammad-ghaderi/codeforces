// https://codeforces.com/contest/567/problem/C

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
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define endl "\n"
#define _MOD (1000000007)
#define MOD(n) (((n % _MOD) + _MOD) % _MOD)
// #define ONLINE_JUDGE

int n, k;
vi a;

unordered_map<int,int> l{}, r{};

void solve() {
    cin >> n >> k;
    a.resize(n);
    FOR(i,0,n) {
        cin >> a[i];
        
        if (r.find(a[i]) == r.end()) r[a[i]] = 1;
        else r[a[i]]++;
    }

    int ans = 0;
    FOR(i,0,n) {
        r[a[i]]--;
        if (a[i]%k==0) {
            int left = (l.find(a[i]/k) == l.end()) ? 0 : l[a[i]/k];
            int right = r[a[i]*k];
            ans += left*right;
        }

        if (l.find(a[i]) == l.end()) l[a[i]] = 1;
        else l[a[i]]++;
    }
  
    cout << ans << endl;
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
