#include<iostream>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;


void solve() {
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int f = a[0], l = a[n-1];
    int first = 0, last = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == f) first++;
        else {
                int j = n-1;
                while (j>i) {
                    if (a[j] == f) first++; 
                    else break;
                    j--;
                }
                break;
            };;
    }
    if (first < n/2 +1)
        for (int i = n-1; i >= 0; i--) {
            if (a[i] == l) last++;
            else break;
        }
    
    int ans = max(first, last);
    cout << n-ans << endl;
}

int main() {
    ghaderi
    int t;
    cin >> t;
    while (t--) solve();

    return 0; 
}