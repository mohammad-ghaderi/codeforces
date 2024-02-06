#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

void solve() {
    int n;
    cin >> n;
    int a[n+1]{0},b[n+1]{0};
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    ll mx = -1e16;
    for (int i = n-1; i >= 0; i--) {
        b[i] = a[i];
        if (abs(a[i])%2 != abs(a[i+1])%2) 
            b[i] += max(0,b[i+1]);
        mx = max((ll)b[i], mx);
    }
    cout << mx << endl;
}

int main () {
    ghaderi;

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}