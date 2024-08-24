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

// const int SIZE = 1e5 + 5;
const int SIZE = 5;
int n;
pair<ll,int> a[SIZE], b[SIZE];
bool mem[SIZE], vis[SIZE];
int e[SIZE][2];

bool dfs(int cur) {
    if (cur == a[n-1].ss) return true;
    if (vis[cur]) return mem[cur];
    vis[cur] = true;

    bool ans = false;
    rep(x, 0, 2) {
        if (e[cur][x] != -1 and !vis[e[cur][x]]) {
            ans |= dfs(e[cur][x]);
        }
    }

    vis[cur] = true;
    return mem[cur] = ans;
}


void solve() {
    cin >> n;
    rep(i, 0, n) cin >> a[i].first, a[i].second = i;
    rep(i, 0, n) cin >> b[i].first, b[i].second = i;

    sort(a, a + n);
    sort(b, b + n);

    rep(i, 0, n) {
        vis[i] = false;
        e[i][0] = -1;
        e[i][1] = -1;
    }

    rrep(i, n - 1, 1) {
        e[a[i].ss][0] = a[i - 1].ss;
    }

    rrep(i, n - 1, 1) {
        if (b[i].ff > b[i - 1].ff) {
            if (e[b[i].ss][0] == -1) e[b[i].ss][0] = b[i - 1].ss;
            else e[b[i].ss][1] = b[i - 1].ss;
        }
    }

    rep(i, 0, n) {
        cout << (dfs(i)?"1":"0");
    }
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