#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long 
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE

int sym[27]{};
int cnt[27]{};

void solve() {
    int n, m;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    
    cin >> m;
    string b[m];
    for (int i = 0; i < m; i++) cin >> b[i];

    map<int,vector<int>> mp{};

    for (int i = 0; i < n; i++) {
        mp[a[i]].emplace_back(i);
    }

    

    for (int p = 0; p < m; p++) {
        string s = b[p];
        if (s.size() != n) {
            cout << "NO\n";
            continue;
        }

        for (int c = 0; c < 27; c++) cnt[c] = 0;
        for (int c = 0; c < n; c++) cnt[s[c]-'a']++;

        bool answer = true;

        for (const auto& x: mp) {
            int key = x.first; auto &nums = x.second;
            char y = s[nums[0]];
            if (nums.size() != cnt[y-'a']) {
                answer = false;
                break;
            }
            for (int b: nums) {
                if (s[b] != y) {
                    answer = false;
                    break;
                } 
            }

            if (!answer) break;
        }  

        if (answer) cout << "YES\n";
        else cout << "NO\n";

    }

    mp.clear();

}


int32_t main() {
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