#include<bits/stdc++.h>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;
#define ONLINE_JUDGE



void solve() {
    ll n;
    cin >> n;
    ll a[n];
    ll rep[n]{};
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i]<n) rep[a[i]]++;
    }

    int m = n;
    for (ll i = 0; i < n; i++) 
        if (rep[i]==0){
            m = i;
            break;
        }
    ll ans{},an{}, answer{}, cnt{}, mn{n*n},mm;
    ll d[n]{};
    for (ll i = 0; i < n; i++) {
        cnt = rep[i];
        ans = (cnt-1)*m + i;
        mm = i;
        answer = 1e9;
        for (ll j = 0; j <= i; j++) {
            an = ans;
            an += (rep[j]-1) * mm + j;
            an += d[j];
            answer = min(an, answer);
            d[i] = answer-ans;
        }
        mn = min(mn, answer);
    }
    
    cout << mn << '\n';
}



int main() {
    ghaderi
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
