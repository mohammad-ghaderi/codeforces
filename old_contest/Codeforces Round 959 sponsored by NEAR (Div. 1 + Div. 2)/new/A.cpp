#include<bits/stdc++.h>

using namespace std;

bool solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int val = a[n-1];
    int cnt = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        if (val == a[i]) {
            cnt++;
        } else {
            if (cnt&1) return true;
            cnt = 1;
            val = a[i];
        }
    }

    if (cnt&1) return true;
    return false;
    
}

int main() {
    int tc = 1;
    cin >> tc;
    while (tc--) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}