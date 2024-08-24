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



bool solve() {
    int n, m, a, b, d;
    cin >> n >> m;
    bool vis[n+1]{}, comp[m+1]{};
    ll pos[n+1]{};

    tuple<int,int,ll> cond[m];
    vector<int> idx[n+1];

    int p = m;
    while (p--) {
        cin >> a >> b >> d;
        cond[p] = {a,b,d};
        idx[a].push_back(p);
        idx[b].push_back(p);
    }
    queue<int> q;

    for (int i = 0; i < m; i++) {
        if (!comp[i]) {
            q.push(i);

            while (q.size()) {
                int id = q.front();
                q.pop();
                if (comp[id]) continue;
                comp[id] = true;

                tuple<int,int,ll>& t = cond[id];
                a = get<0>(t);
                b = get<1>(t);
                d = get<2>(t);
            
                if (!vis[a]) {
                    for (auto x: idx[a]) {
                        if (!comp[x]) q.push(x);
                    }
                }
                if (!vis[b]) {
                    for (auto x: idx[b]) {
                        if (!comp[x]) q.push(x);
                    }
                }

                if (vis[a] and vis[b]) {
                    // check
                    if (pos[b] - pos[a] != d) return false;
                } else if (vis[a]) {
                    // add
                    pos[b] = d + pos[a];
                } else if (vis[b]) {
                    // add
                    pos[a] = pos[b] - d;
                } else {
                    // add position 0 (random)
                    pos[a] = 0ll;
                    pos[b] = d + pos[a]; 
                }
                vis[a] = true;
                vis[b] = true;
            }
        }
    }
    
    return true;
}


int main() {
    fastio
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while (t--) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}