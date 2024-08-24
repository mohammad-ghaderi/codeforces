#include<bits/stdc++.h>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;
// #define ONLINE_JUDGE


int n,k;
vector<int> parent, ranking;
vector<pair<int,int>> edges;

void make_set(int v) {
    parent[v] = v;
    ranking[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ranking[a] < ranking[b])
            swap(a, b);
        parent[b] = a;
        if (ranking[a] == ranking[b])
            ranking[a]++;
    }
}


void removeEdge() {
    int mx = 0, rnk1, rnk2;
    for (int i = 0; i < n-1; i++) {
        rnk1 = ranking[edges[i].first];
        rnk2 = ranking[edges[i].second];
        mx = max(mx, min(rnk1,rnk2))
    }
    
}




void solve() {
    cin >> n >> k;
    parent.resize(n);
    ranking.resize(n);
    edges.resize(n-1);
    for (int i = 0; i < n; i++) make_set(i);
    for (int i = 0; i < n-1; i++) {
        cin >> edges[i].first >> edges[i].second;
        union_sets(edges[i].first, edges[i].second);
    }
    
    while (k--) removeEdge();

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
