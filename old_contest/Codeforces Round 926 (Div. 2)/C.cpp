#include<iostream>
#include<algorithm>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;

bool solve() {
    ll k, x, a, A;
    cin >> k >> x >> a;
    ll y = 1; A = a;
    for (int i = 0; i < x; i++) {
        y = (A-a)/(k-1)+1;
        y = max(1ll, y);
        a -= y;
        if ((a+(k*y)) < A || a<=0) return false;
    }
    if (a*k <= A) return false;
    return true;
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