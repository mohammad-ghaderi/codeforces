#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long 
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE



void solve() {
    int n, k;
    cin >> n >> k;

    int a[2*n];
    for (int i = 0; i < 2*n; i++) cin >> a[i];

    int cnt[n+1]{};

    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }

    queue<int> q1_2{}, q1_1{}, q2_2{}, q2_1{};
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 2) q1_2.push(i);
        else if (cnt[i] == 1) q1_1.push(i), q2_1.push(i);
        else q2_2.push(i);
    }

    queue<int> ans1{}, ans2{}; 
    for (int i = 0; i < 2*k; i++) {
        if (i + 1 < 2*k and !q1_2.empty()) {
            ans1.push(q1_2.front());
            ans1.push(q1_2.front());
            ans2.push(q2_2.front());
            ans2.push(q2_2.front());
            q1_2.pop();
            q2_2.pop();
            i++;
        } else {
            ans1.push(q1_1.front());
            ans2.push(q2_1.front());
            q1_1.pop();
            q2_1.pop();
        }
    }

    while(!ans1.empty()) cout << ans1.front() << ' ', ans1.pop();
    cout << endl;
    while(!ans2.empty()) cout << ans2.front() << ' ', ans2.pop();
    cout << endl;
    

}


int main() {
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