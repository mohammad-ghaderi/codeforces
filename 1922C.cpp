#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    ll a[n+2]{0}, toRight[n+1]{0}, toLeft[n+1]{0};
    a[n+1] = 10e12;
    a[0] = 10e12;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    for (int i = 1; i <= n; i++) {
        ll lft = abs(a[i]-a[i-1]), rgt = abs(a[i]-a[i+1]);
        toRight[i] = max(toRight[i-1], (ll) 0);
        if (rgt < lft)
            toRight[i] += min((ll) 1, rgt);
        else toRight[i] += rgt;
    }
    for (int i = n; i >= 1; i--) {
        ll lft = abs(a[i]-a[i-1]), rgt = abs(a[i]-a[i+1]);
        toLeft[i] = max(toLeft[i+1], (ll) 0);
        if (lft < rgt)
            toLeft[i] += min((ll) 1, lft);
        else toLeft[i] += lft;
    }
    // queries
    int m, start, end;
    cin >> m;
    while (m--) {
        cin >> start >> end;
        if (start < end) 
            cout << (toRight[end-1]-toRight[start-1]) << endl;
        else
            cout << (toLeft[end+1]-toLeft[start+1]) << endl;
    }
    
    
}

int main () {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}