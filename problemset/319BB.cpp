#include<bits/stdc++.h>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;
#define ONLINE_JUDGE

ll n,m,x;
vector<ll> a;

bool fnc() {
    
    vector<bool> mem(m,false), memt(m,false);

    for (auto x : a) {
        if (mem[m-x] or x==0) return true;
        for (ll i = 0; i < m; i++)
            if (mem[i])
                memt[(x+i)%m] = true;
    
        mem[x] = true;
        for (ll i = 0; i < m; i++) mem[i] = mem[i] or memt[i];
    }
    return false;
}

void solve() {
    cin >> n >> m;
    a.resize(n);
    for (ll i = 0; i < n; i++) cin >> a[i], a[i] %= m;
    

    if (fnc()) cout << "YES";
    else cout << "NO";
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
