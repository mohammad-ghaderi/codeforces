#include<iostream>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;


void solve() {
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    
    ll current_year = 1;
    for (int i = 0; i < n; i++) {
        if (current_year <= a[i]) current_year = a[i]+1;
        else {
            ll zarib = current_year%a[i]==0?current_year/a[i]:current_year/a[i]+1;
            current_year = a[i]*zarib+1;
        }
    }
    cout << current_year-1 << endl;
}

int main() {
    ghaderi
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}