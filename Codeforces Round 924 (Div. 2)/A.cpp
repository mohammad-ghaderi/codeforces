#include<iostream>
#include<algorithm>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;

bool solve() {
    ll x, y;
    cin >> x >> y;
    if (x%2!=0 and y%2!=0) return false;
    if (x%2==0 and y%2==0) return true;
    if (x%2==0 and x/2 == y) return false;
    if (y%2==0 and y/2 == x) return false;
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

