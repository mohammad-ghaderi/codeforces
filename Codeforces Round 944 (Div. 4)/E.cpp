#include<bits/stdc++.h>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long int
#define pii pair<int,int>
#define vi vector<int>
#define endl "\n"
#define _MOD (1000000007)
#define MOD(n) (((n % _MOD) + _MOD) % _MOD)
// #define ONLINE_JUDGE

const int N = 1e5 + 1;

struct Bluck
{
    int dist = 0;
    int time = 0;
};




void solve() {
    int n, k, q, d;
    cin >> n >> k >> q;
    Bluck mp[k+1];

    for (int i = 1; i <= k; i++) cin >> mp[i].dist;

    for (int i = 1; i <= k; i++) cin >> mp[i].time;
    

    // for (int i = 0; i <= k; i++) cout << mp[i].dist << ' ' << mp[i].dist << endl;
    
    while (q--) {
        cin >> d;

        // binary search

        int low = 0;
        int hi = k-1;
        int mid;

        while (low <= hi) {
            mid = low + (hi - low)/2;

            if (d < mp[mid].dist ) {
                hi = mid - 1;
            } else if(d > mp[mid].dist and (mid < k-1) and d > mp[mid+1].dist ) {
                low = mid + 1;
            } else {
                // ans
                break;
            }
        }
        
        int ans = mp[mid].time;
        d -= mp[mid].dist;

        // cout << (mp[mid+1].dist - mp[mid].dist) << ' ' << (mp[mid+1].time - mp[mid].time)  << endl;
        int dif = mp[mid+1].dist - mp[mid].dist;
        int tm = mp[mid+1].time - mp[mid].time;

        ans += d * tm / dif;
        
        cout << ans << ' ';

    }
    cout << endl;

}



int32_t main() {
    ghaderi
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
