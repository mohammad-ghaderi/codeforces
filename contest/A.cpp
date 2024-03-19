#include<iostream>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

void solve() {
    string s;
    cin >> s;
    int mx = 0;
    int a = 0, b = 0;
    for (char c :s) {
        if (c=='A')a++;
        else b++;
    }
    if (a>b) cout << "A\n";
    else cout << "B\n";
}

int main() {
    ghaderi
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}