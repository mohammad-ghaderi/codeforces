#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int solve() {
    int n, m, k;
    ll t;
    cin >> n >> m >> k;
    set<ll> a, b;
    for (int i = 0; i < n; i++){
        cin >> t;
        a.insert(t);
    }
    for (int i = 0; i < m; i++){
        cin >> t;
        b.insert(t);
    }
    if (a.size() < k/2 || b.size() < k/2) return false;

    int rep = 0, ac = 0, bc = 0;
    int mid = k/2;

    for (int i = 1; i <= k; i++) {
        const bool is_in_a = a.find(i) != a.end();
        const bool is_in_b = b.find(i) != b.end();
        
        if (is_in_a && is_in_b) rep++;
        else if (is_in_a) ac++;
        else if (is_in_b) bc++;
        else return false;

        if (ac>k/2 || bc>k/2) return false;
    }

    int acdiff = k/2 - ac;
    int bcdiff = k/2 - bc;

    if (acdiff > rep) return false;
    rep -= acdiff;
    if (bcdiff > rep) return false;
    rep -= bcdiff;
    if (rep!=0) return false;
    return true;
}

int main () {
    ghaderi;

    int t;
    cin >> t;
    while (t--){
        if (solve()) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}