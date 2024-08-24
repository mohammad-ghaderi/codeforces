#include<iostream>
#include<algorithm>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;


void solve() {
    ll n;
    cin >> n;
    ll numb = n;
    ll answer = 0;
    int ex = 0;
    int y = 1;
    while (numb) {
        int mod = numb%10;
        ex*=10; ex+= mod;
        numb/=10;
        for (int i = 1; i < mod; i++) answer += (numb+1)*(y)*i;
        answer += (numb)*(y)*mod + (ex+1)*mod;
        for (int i = mod+1; i <= 9; i++) answer += (numb)*(y)*i;
        y*=10;
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