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



void solve() {
    int n;
    cin >> n;
    vll a(n);
    FOR(i,0,n) cin >> a[i];
    unordered_map<ll,int> mem{};
    
    ll ans = 0, mx = 0;
    EACH(e,a) {
        auto iter1 = mem.find(e);
        auto iter2 = mem.find(e-1);
        int bef = iter2!=mem.end() ? iter2->second : 0;
        if (iter1!=mem.end()) iter1->second = max(iter1->second, bef + 1);
        else  mem[e] = bef + 1;
        
        mem[e] = max(mem[e-1]+1, mem[e]);
        if (mx<mem[e]) mx = mem[e], ans = e;
    }
    cout << mx << endl;
    stack<int> s{};
    RFOR(i,n-1,0) {
        if (mx == 0) break;
        if (a[i] == ans) s.push(i+1), ans--, mx--;
    }
    while (!s.empty()) cout << s.top() << ' ', s.pop();
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
