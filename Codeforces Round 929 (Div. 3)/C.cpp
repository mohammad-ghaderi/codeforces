#include<iostream>
#include<unordered_set>
#include<cmath>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;

ll cont(ll x, ll y) {
    ll cnt = 0;
    while (x%y == 0) {
        x /= y;
        cnt++;
    }
    return cnt;
}

bool check(ll x, ll y) {
    while (x%y == 0) x /= y;
    if (x == 0) return true;
    return false;
    
}

void solve() {
    ll a, b, l, vl;
    cin >> a >> b >> l;
    ll an = cont(l, a);
    ll bn = cont(l, b);
    unordered_set<ll> s{};

    for (size_t i = 0; i <= an; i++) {
        for (size_t j = 0; j <= bn; j++) {
            vl = static_cast<ll>(pow(a,i)*pow(b,j));
            if ( vl <= l and l%vl==0) s.insert(vl);
            else break;
        }
    }
    cout << s.size() << '\n';
}

int main() {
    ghaderi
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}