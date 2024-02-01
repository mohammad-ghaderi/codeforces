#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    ll a[n];
    ll mn{};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < a[mn]) mn = i;
    }
    
    for (int i = mn +1; i < n; i++) {
        if (a[i] < a[i-1]) {
            cout << -1 << endl;
            return;
        }
    }
    cout << mn << endl; 
}

int main () {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}