#include<iostream>
#include<algorithm>
using namespace std;

#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    
    int k = 1;
    bool f = true;
    int end = n%2 == 0? n/2 : n/2+1;
    int c = 0;
    while (c<n) {
        if (f) cout << k << " ";
        else {cout << n-k+1 << " ";
        k++;}
        f = !f;
        c++;
    }
    cout << endl;
}


int main() {
    ghaderi
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}