#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE



void solve() {
    int n;
    cin >> n;
    int cnt[n]{};
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }
    int I;
    for (I = 0; I < n; I++) {
        if (cnt[I] == 0) break;
    }
    int i;
    int c = 0;
    for (i = 0; i < I; i++) {
        if (cnt[i] == 1) c++;
        if (c == 2) break;
    }

    cout << i << endl;
}


int main() {
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