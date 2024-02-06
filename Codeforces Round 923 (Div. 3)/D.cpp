#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

void solve() {
    int n,q,right,left;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) 
        cin >> a[i];    
    int dp[n+1];
    dp[n] = -1;
    dp[n-1] = -1;

    for (int i = n-2; i >= 0; i--) {
        if (a[i] == a[i+1]) dp[i] = dp[i+1];
        else dp[i] = i+2;
    }
    
    cin >> q;
    while (q--) {
        cin >> left >> right;
        if (dp[left-1] == -1 || dp[left-1] > right) cout << -1 << " " << -1 << endl;
        else cout << left << " " << dp[left-1] << endl;
    }
    
    
}

int main () {
    ghaderi;

    int t;
    cin >> t;
    while (t--){
        solve();
        if (t) cout << endl;
    }
    return 0;
}