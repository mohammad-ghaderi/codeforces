#include<iostream>
#include<algorithm>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;


bool solve() {
    ll n;
    cin >> n;
    ll a[n];
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a, a+n);
    for (size_t i = 0; i<n-1; i++ ) {
        if (a[i]%a[i+1]==0) return 0
    }
    return false;
}

int main() {
    ghaderi
    int t;
    cin >> t;
    while (t--) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}