#include<bits/stdc++.h>

using namespace std;

bool solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s;
    cin >> t;

    for (int i = 0; i< n;i++) {
        if (s[i] == '1') return true;
        if (s[i] == '0' and t[i] == '1') return false;
    }
    
    return true;
}

int main() {
    int tc = 1;
    cin >> tc;
    while (tc--) 
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    return 0;
}