#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long 
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE
const int SIZE = 2e5 + 5;
int n;

int a[SIZE]{}, sum[SIZE]{};


void solve() {
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    int sm = 0;
    sum[0] = 0;
    for (int i = 0; i < n; i++) {
        sm += a[i];
        sum[i+1] = sm;
    }


    string s;
    cin >> s;

    int i = 0, j = n-1;
    int answer = 0;

    while(i < j) {
        while(i < j and s[i] != 'L') i++;
        while(j > i and s[j] != 'R') j--;

        if (i >= j) break;
        if (s[i]!='L' or s[j]!='R') break;

        answer += sum[j+1] - sum[i];
        i++; j--;
    }


    cout << answer << endl;
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