#include<iostream>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int b[n], c[m];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < m; i++) cin >> c[i];
    long long cnt = 0;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            if (b[i]+c[j] <= k) cnt++;
        
    cout << cnt << '\n';
    
}

int main() {
    ghaderi
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}