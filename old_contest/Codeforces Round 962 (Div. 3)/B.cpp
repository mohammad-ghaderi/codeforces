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

bool solve() {
    int n, k;
    cin >> n >> k;

    string s[n];

    int ans[n/k][n/k]{};

    for (int i = 0; i < n; i++) cin >> s[i];

    int val = -1;
    bool stats = true;

    for (int i = 0; i < n/k; i++) {
        for (int j = 0; j < n/k; j++) {

            for (int I = i*k; I < (i+1)*k; I++) {
                for (int J = j*k; J < (j+1)*k; J++) {
                    if (val == -1) val = (s[I][J]) - '0';
                    else if (val != (s[I][J]) - '0') {
                        stats = false;
                        return false;
                    }
                }
            }
            ans[i][j] = val;
            val = -1;
        }
    }

    
    for (int i = 0; i < n/k; i++) {
        for (int j = 0; j < n/k; j++)
            cout << ans[i][j];
        cout << endl;
    }

    return true;

}



int main() {
    ghaderi
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll t = 1;
    cin >> t;
    while (t--) {
        if (!solve()) cout << "0\n";
    }

    return 0;
}