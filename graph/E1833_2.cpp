// https://codeforces.com/problemset/problem/1833/E
#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long 
#define ld long double
#define vll vector<ll>
#define vv vector<vll>
#define pb push_back
#define lb lower_bound2
#define ub upper_bound
#define pll pair<ll,ll>
#define vpll vector<pll>
#define ff first
#define ss second
#define tll tuple<ll,ll,ll>
#define vtll vector<tll> 
#define mt make_tuple
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define each(e, a) for (auto& e : a)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define vect(a,n) vll a(n); rep(i,0,n) cin>>a[i];
#define all(a) a.begin(),a.end()
#define sortall(a) sort(a.begin(),a.end());
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define endl "\n"


//Debug
#define printv(a) rep(i,0,a.size()) cout<<a[i]<<" "; cout<<endl;
#define pout(p) cout<<"("<<p.ff<<","<<p.ss<<")"<<" ";
#define printvp(a) rep(i,0,a.size()) cout<<"("<<a[i].ff<<","<<a[i].ss<<")"<<" "; cout<<endl;
#define tout(t) cout<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")"<<endl;
#define trace(x) cout<< '>' << #x << ':' << (x) << "\n";
#define trace2(x,y) cout<< '>' << #x << ':' << (x) << " | " << #y << ':' << (y) << "\n";
#define trace3(a,b,c) cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n";
#define trace4(a,b,c,d) cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n";


using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }

// #define ONLINE_JUDGE


struct graph {
    int v;
    vector<int> *l;
    vector<bool> vis;

    graph(int v) {
        this->v = v;
        this->l = new vector<int>[v];
        this->vis = vector<bool>(v, false);
    }

    void add_edge(int a, int b, bool undir=true) {
        l[a].push_back(b);
        if (undir) l[b].push_back(a);
    }

    void print_edge_list() {
        for (int i = 0; i < v; i++) {
            cout << i << ":";
            for (auto x : l[i]) cout << x << ", ";
            cout << endl; 
        }
    }

    bool dfs(int cur, int par) {
        bool ans = false;
        vis[cur] = true;

        for (auto x: l[cur]) {
            if (x == par) continue;
            if (vis[x]) {
                ans = true;
            } else {
                ans = ans or dfs(x, cur);
            }
        }

        return ans;
    }
};


void solve() {
    int n;
    cin >> n;
    
    int a[n];

    graph g(n+1);
    rep(i, 0, n) {
        cin >> a[i];
    }

    rep(i, 0, n) {
        if (a[a[i]-1] != i+1 or a[i] > i+1) {
            g.add_edge(a[i], i+1);
        }
    }

    // g.print_edge_list();

    bool stat = false;
    int mn = 0, mx = 0;

    rep(i, 1, n+1) {
        if (!g.vis[i]) {
            bool an = g.dfs(i, 0);
            if (an) {
                mn++; 
                mx++;
            } else {
                if (stat) {
                    mx++;
                } else {
                    stat = true;
                    mx++;
                    mn++;
                }
            }
        }
    }

    cout << mn << ' ' << mx << endl;

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