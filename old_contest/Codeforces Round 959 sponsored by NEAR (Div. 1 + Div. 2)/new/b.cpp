#include<bits/stdc++.h>
#define ghaderi ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

void solve() {

    int n, x, y;
    cin >> n >> x >> y;

    int a[n];

    x--;y--;

    int num = -1;
    for (int i = y - 1; i >= 0; i--) {
        a[i] = num;
        num *= -1;
    }

    num = -1;
    for (int i = x+1; i < n; i++) {
        a[i] = num;
        num *= -1;
    }

    for (int i = y; i <= x; i++) a[i] = 1;

    for (int i = 0; i < n; i++) cout << a[i] << ' ';

    cout << endl;
}

int main() {
    ghaderi
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}