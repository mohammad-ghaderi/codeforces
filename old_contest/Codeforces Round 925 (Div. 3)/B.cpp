#include<iostream>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;


bool solve() {
    int n;
    cin >> n;
    ll a[n];
    ll sum = 0, avg = 0, extra = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    avg = sum / n;
    for (int i = 0; i < n; i++) {
        if (a[i]< avg) {
            if (avg - a[i] <= extra) {
                extra -= avg - a[i];
            } else return false;
        } else if (a[i] > avg) {
            extra += a[i] - avg;
        }
    }
    if (extra == 0) return true;
    return false; 
}

int main() {
    ghaderi
    int t;
    cin >> t;
    while (t--) {
        if (solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0; 
}