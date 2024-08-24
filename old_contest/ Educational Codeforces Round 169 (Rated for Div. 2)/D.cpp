#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long 
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }


// #define ONLINE_JUDGE
const int inf = 1e7;
const int SIZE = 2e5 + 5;
int n, q;

string portal[SIZE]{};
int pref[SIZE][4]{}, post[SIZE][4]{};
map<pair<int,int>,int> mem{};
bool colors[SIZE][4]{};
bool vis[SIZE]{};

int fnd(int x, int y) {
    if (x > y) return fnd(y, x);
    if (mem.find({x, y}) != mem.end()) return mem[{x,y}];
    if (vis[x]) return inf;
    vis[x] = true;

    for (int i = 0; i < 4; i++) {
        if (colors[x][i] and colors[y][i]) {
            return mem[{x,y}] = mem[{y,x}] = y - x;
        }
    }

    int dist = inf;
    for (int i = 0; i < 4; i++) {
        if (colors[x][i] and post[x][i] != -inf) {
            int an = fnd(post[x][i], y);
            if (an == inf) continue;
            an += post[x][i] - x;
            dist = min(dist, an);
        }
    }

    for (int i = 0; i < 4; i++) {
        if (colors[x][i] and pref[x][i] != -inf) {
            int an = fnd(pref[x][i], y);
            if (an == inf) continue;
            an += x - pref[x][i];
            dist = min(dist, an);
        }
    }
    
    return mem[{y,x}] = mem[{x,y}] = dist;
}

void solve() {
    cin >> n >> q;

    for (int i = 0; i < n; i++) cin >> portal[i];

    int cp[4] = {-inf, -inf, -inf, -inf}; // G, R, Y, B

    for (int i = 0; i < n; i++) {
        if (portal[i][0] == 'G' or portal[i][1] == 'G') colors[i][0] = true;
        else colors[i][0] = false;
        if (portal[i][0] == 'R' or portal[i][1] == 'R') colors[i][1] = true;
        else colors[i][1] = false;
        if (portal[i][0] == 'Y' or portal[i][1] == 'Y') colors[i][2] = true;
        else colors[i][2] = false;
        if (portal[i][0] == 'B' or portal[i][1] == 'B') colors[i][3] = true;
        else colors[i][3] = false;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < 4; j++) {
            if (colors[i][j]) cp[j] = i;
        }

        for (int j = 0; j < 4; j++) pref[i+1][j] = cp[j];
    }

    int cs[4] = {-inf, -inf, -inf, -inf}; // G, R, Y, B

    for (int i = n-1; i > 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (colors[i][j]) cs[j] = i;
        }

        for (int j = 0; j < 4; j++) post[i-1][j] = cs[j];
    }

    mem.clear();

    int x, y;

    while(q--) {
        cin >> x >> y;
        for (int i = 0; i < n; i++) vis[i] = false;
        int an = fnd(x-1, y-1);
        if (an == inf) cout << "-1\n";
        else cout << an << endl;
    }

    

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