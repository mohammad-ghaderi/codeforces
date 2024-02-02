#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    ll a[n], b[n+1]{0};
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    
    for (int i = n-1; i >= 0; i--) {
        if (i+a[i] >= n) b[i] = min(b[i+1]+1,(ll) 1+n-i);
        else b[i] = min(b[i+1]+1, b[i+a[i]+1]);
    }
    cout << b[0] << endl;
}

int main () {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}