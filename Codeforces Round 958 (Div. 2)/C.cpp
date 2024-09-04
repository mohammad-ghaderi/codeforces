#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE



void solve() {
    int n;
    cin >> n;

    bitset<61> b(n);

    int i = 0;
    stack<int> st{};
    st.push(n);

    for (int i = 0; i < 63; i++) {
        if (b[i]) {
            bitset<62> t(n);
            t.set(i,0);
            if (t.to_ullong() != 0) st.push(t.to_ullong());
        }
    }
    cout << st.size() << endl;
    while(!st.empty()) cout << st.top() << ' ', st.pop();
    cout << endl;
}


int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}