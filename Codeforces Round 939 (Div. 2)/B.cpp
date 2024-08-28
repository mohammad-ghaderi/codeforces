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
    int a[n+1]{};

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        a[x]++;
    }

    int me = 0, him = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 2) me++;
        if (a[i] == 0) him++;
    }

    if (me > him) {
        cout << n - him << endl;
    } else {
        cout << me << endl;
    }

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