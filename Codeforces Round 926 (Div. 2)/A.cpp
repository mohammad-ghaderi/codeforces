#include<iostream>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


void solve() {
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    
    long long mx = a[0], mn = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i]>mx) mx = a[i];
        if (a[i]<mn) mn = a[i];
    }
    cout << (mx - mn) << endl;
    
}

int main() {
    ghaderi
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}