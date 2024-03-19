#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> numbers(n), tabel(n+1);
    ll ans;
    for (int i = 0; i < n; i++) cin >> numbers.at(i), tabel[i] = LLONG_MAX;

    for (int i = n-1; i >= 0; i--) 
        for (int j = i; j < n; j++) {
            ans = tabel[j+1]-numbers[i] >= 0 ? tabel[j+1]-numbers[i] : 0ll;
            if (ans < tabel[j]) tabel[j] = ans;
            else break;
        }
    
    for (int i = 0; i <= n; i++) 
        if (tabel[i] == 0){
            cout << n - i;
            return;
        }
}

int main() {
    ghaderi
    solve();
    return 0;
}