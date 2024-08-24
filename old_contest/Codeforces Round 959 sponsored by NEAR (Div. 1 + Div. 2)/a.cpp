#include<bits/stdc++.h>

using namespace std;

void solve() {

    int n, m;
    cin >> n >> m;


    int b[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }
    if (n <= 1 and m <= 1) {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j+=1) {
            int t = b[i][j];
            b[i][j] = b[i][j+1];
            b[i][j+1] = t;
        }
    }

    if (m&1) {
        for (int i = 0; i < n - 1; i+=1) {
            int t = b[i][m-1];
            b[i][m-1] = b[i+1][m-1];
            b[i+1][m-1] = t;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j< m; j++) {
            cout << b[i][j] << ' ';
        }
        cout << endl;
    }
    
    
}

int main() {
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}