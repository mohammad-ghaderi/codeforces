#include<bits/stdc++.h>

using namespace std;
int n, x;

int dp(int i, int j, int sm) {


    if (sm + a[i] <= x) {
        
    }

}


void solve() {
    cin >> n >> x;
    long long a[n];

    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dp(i, i);
    }
}

int main() {
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}