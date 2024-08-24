#include<iostream>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;


void solve() {
    int n;
    cin >> n;
    int numb = 1;
    int answer = 0;
    while (numb<=n) {
        int sm = 0;
        int x = numb;
        while (x!=0) {
            sm+=x%10;
            x/=10;
        }
        answer += sm;
        numb++;
    }
    cout << answer << endl;
}


int main() {
    ghaderi
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}