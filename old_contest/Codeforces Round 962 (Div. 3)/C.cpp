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
    int n, q;
    cin >> n >> q;

    string a, b;
    cin >> a;
    cin >> b;

    int rep_a[n+1][28]{}, rep_b[n+1][28]{};

    for (int i = 1; i <= n; i++) {

        for (int c = 0; c < 28; c++) {
            rep_a[i][c] = rep_a[i-1][c];
            rep_b[i][c] = rep_b[i-1][c];

        }
    
        rep_a[i][a[i-1]-'a']++;
            
        rep_b[i][b[i-1]-'a']++;
        
    }


    while (q--) {
        int s, e;
        cin >> s >> e;

        // s--;e--;

        int a_cnt = 0, b_cnt = 0;

        for (int i = 0; i < 28; i++) {
            int repa = rep_a[e][i] - rep_a[s-1][i];
            int repb = rep_b[e][i] - rep_b[s-1][i];

            if (repa > repb) {
                a_cnt += repa - repb;
            } else if (repa < repb) {
                b_cnt += repb - repa;
            }
        }

        cout << b_cnt << endl;
    }

}



int main() {
    ghaderi
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}