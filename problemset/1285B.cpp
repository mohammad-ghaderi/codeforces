#include<iostream>

using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;
bool solve() {
    int n;
    cin >> n;
    ll cup, adel1 = 0, adel2 = 0, yaser = 0;
    bool adb1 = false;
    for (int i = 1; i <= n; i++) {
        cin >> cup;
        yaser += cup;
        if (i != n or adb1) {
            if (adel1 + cup <= 0) {
                adb1 = true;
                adb1 = 0;
            }
        } 
    }
    
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        if (solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}