#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }

// #define ONLINE_JUDGE

const int SIZE = 2e5 + 5;
const int inf = 1e18;
int N, M, t;

vector<tuple<int,int,int>> g[SIZE]{};
int dist[SIZE]{};
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq{}; // time, intersection


int dijk() {

    for (int i = 1; i <= N; i++) dist[i] = inf;
    
    pq.emplace(t, 1);
    dist[1] = t;

    while(!pq.empty()) {
        auto [tim, u] = pq.top();
        pq.pop();

        if (tim > dist[u]) continue;

        for (auto &[v, x, y]: g[u]) {
            int md = tim % (x+y);
            int next_time = tim;  
            if (md >= x) next_time += (x + y - md);
            if (dist[v] > next_time) {
                pq.emplace(next_time, v);
                dist[v] = next_time;
            }
        }
    }

    return dist[N];
}


void solve() {
    cin >> N >> M >> t;
    
    for (int i = 0, a, b, x, y; i < M; i++) {
        cin >> a >> b >> x >> y;
        g[a].emplace_back(b, x, y);
        g[b].emplace_back(a, x, y);
    }

    int answer = dijk();

    cout << answer << endl; 
}


int32_t main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}