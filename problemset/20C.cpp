// https://codeforces.com/problemset/problem/20/C


#include<bits/stdc++.h>
#define int long long int
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
const int INF = 1e15;

class Graph{

    int v;
    vector<pair<int,int>> *l;

public:

    Graph(int n){
        v = n;
        l = new vector<pair<int,int>>[n];
    }


    void addEdge(int u, int v, int w, bool undir = true) {
        l[u].push_back({w,v});
        if (undir) l[v].push_back({w, u});
    }

    void printAdj() {
        for (int i = 1; i < v; i++) 
            for (auto x: l[i]) printf("%d == %d : %d \n", i, x.second, x.first);
    }


    void shortest_path() {
        
        set<pair<int,int>> s;
        vector<pair<int,int>> dist(v, {INF,INF}); // value, from

        dist[1] = {0,0};

        s.insert({0,1});

        while (!s.empty()) {
            auto it = s.begin();
            int node = it->second;
            int costTillNow = it->first;

            s.erase(it);

            for (auto neighbour: l[node]) {
                int nbr = neighbour.second;
                int weight = neighbour.first;

    

                if (costTillNow + weight < dist[nbr].first) {
                    auto f = s.find({dist[nbr].first, nbr});
                    if (f != s.end()) {
                        s.erase(f);
                    }
                    dist[nbr] = {costTillNow + weight, node};
                    s.insert({dist[nbr].first,nbr});
                }
            }
        }

        if (dist[v-1].first == INF) {
            cout << -1;
            return;
        }


        int n = v - 1;
        vector<int> ans(v);
        int now = n;
        int i = 0;
        while (now) {
            ans[i++] = now;
            now = dist[now].second;
        }

        for (i = i - 1; i >=0; i--) cout << ans[i] << ' ';
        cout << endl;
    }
        
                


};



int32_t main() {
    ghaderi
    int n , m;
    int a, b, w;
    cin >> n >> m;

    Graph g(n+1);

    for (int i = 0; i < m; i++) cin >> a >> b >> w, g.addEdge(a,b,w);

    // g.printAdj();
    
    g.shortest_path();

    return 0;
}
