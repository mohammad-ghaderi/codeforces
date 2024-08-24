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
// const int SIZE = 2e5+1;
const int SIZE = 2e5+5;
vector<int> g[SIZE]{};
int n, m;
int dist[SIZE]{}, ansistor[SIZE]{};


void bfs() {
    for (int u = 1; u <= n; u++) dist[u] = n + 10;
    dist[1] = 1;
    queue<int> q;
    q.push(1);

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == n) continue;

        if (dist[u] + 1 < dist[u + 1] ) {
            dist[u + 1] = dist[u] + 1;
            ansistor[u+1] = u;
            q.push(u+1); 
        }
        for (int v: g[u]) {
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                ansistor[v] = u;
                q.push(v);
            }
        }
    }
}

void solve() {
    cin >> n >> m;

    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }

    bfs();

    stack<bool> stk{};

    int ansis = n;
    int val = n+1;

    for (int u = n; u > 0; u--) {

        if (u == ansis) val = n;

        if (u != n) {

            if (val <= 0) {
                stk.push(false);
            } else {
                stk.push(true);
            }
        }


        if (ansistor[u] < ansis) {
            ansis = ansistor[u];
            val = dist[u];
        }
        val--;
        
    }

    while(!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }
    cout << endl;

    for (int u = 1; u <= n; u++) {
        g[u].clear();
    }
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