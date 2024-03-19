#include<iostream>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

void solve() {
    int n;
    cin >> n;
    string a[n];
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '1') {
                if (a[i+1][j] == '0' or a[i][j+1] == '0') {
                    cout << "TRIANGLE\n";
                } else cout << "SQUARE\n";
                return;
            }
        }
    }
}

int main() {
    ghaderi
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}