#include<iostream>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

void solve() {
    int n;
    cin >> n;
    string p;
    cin >> p;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] == '@') {
            if (i<n-1 and p[i+1]=='*') i++;
            cnt++;
        } else if (p[i] == '.' and i<n-1 and p[i+1]=='*') i++;
        else if (p[i] == '*') break;
    }
    cout << cnt << endl;
}

int main() {
    ghaderi
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}