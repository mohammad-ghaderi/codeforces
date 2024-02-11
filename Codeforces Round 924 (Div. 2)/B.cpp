#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    ll numb;
    set<ll> temp;
    for (int i = 0; i < n; i++) cin >> numb, temp.insert(numb);
    
   
    set<ll>::iterator itr;
    vector<ll> a(temp.size()), b(temp.size()-1);
    int i = 0;
    for (itr = temp.begin(); itr != temp.end(); itr++) a.at(i++) = *itr;
    for (int i = 1; i < a.size(); i++) b.at(i-1) = a.at(i) - a.at(i-1);
    
    int cnt = 0, ans = 1;
    int j = 0;
    ll sm = 1;
    i = 0;
    while (i < b.size() and j < b.size()) {
        sm += b.at(i);
        while (sm > n) sm -= b.at(j++);
        ans = max(ans, i-j+2);
        i++;
    }
    
    cout << ans << endl;
}





int main() {
    ghaderi
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

