#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE



void solve() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];


    if (a[0] == a[n-1]) {
        cout << "NO";
    } else if (a[0] != a[1]) {
        cout << "YES\n";
        for (int i = 0; i < n - 1; i++) cout << "R";
        cout << "B";
    } else if (a[n - 1] != a[n -2]) {
        cout << "YES\n";
        cout << "R";
        for (int i = 1; i < n; i++) cout << "B";
    } else if (a[0] == a[1]) {
        cout << "YES\n";
        cout << "R";
        for (int i = 1; i < n; i++) cout << "B";
    } else if (a[n -1] == a[n - 2]) {
        cout << "YES\n";
        for (int i = 0; i < n - 1; i++) cout << "R";
        cout << "B";
    } else cout << "NO";

    cout << endl;
}


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}