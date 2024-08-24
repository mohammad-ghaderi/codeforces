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

// const int mxN = 2e5+1;
const int mxN = 10;

int parent[mxN]{};
int siz[mxN]{};
bool cycle[mxN]{};
int A[mxN]{};

void make_set(int v) {
    parent[v]=v; siz[v]=1; cycle[v] = false;
}
int find_set(int v) {
    return (v==parent[v])?v:parent[v]=find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) {
        cycle[a] = true;
        return;
    };
    if(siz[a]<siz[b]) swap(a,b);
    parent[b] = a;
    cycle[b] |= cycle[a];
    cycle[a] |= cycle[b];
    siz[a]+=siz[b];
    siz[b]=0;
}
int get_size(int v){
    return siz[find_set(v)];
}

void solve() {
    int n;
    cin >> n;

    rep(i, 0, n+1) 
        make_set(i);
    
    rep(i, 0, n) {
        cin >> A[i];
        if (A[A[i]-1] != i+1)
            union_sets(A[i], i+1);

    }

    rep(i, 0, n+1) {
        if (cycle[find_set(i)]) {
            cycle[i] = true;
        } else if (cycle[i]) {
            cycle[find_set(i)] = true;
        }
    }

    int mn_ans = 0, mx_ans = 0;
    bool status = false;

    bool vis[n+1]{};

    // cout << "i:";
    // rep(i, 0, n+1) cout << i << ' ';
    // cout << endl;

    // cout << "f:";
    // rep(i, 0, n+1) cout << find_set(i) << ' ';
    // cout << endl;

    // cout << "g:";
    // rep(i, 0, n+1) cout << get_size(i) << ' ';
    // cout << endl;

    // cout << "c:";
    // rep(i, 0, n+1) cout << cycle[find_set(i)] << ' ';
    // cout << endl;


    rep(i, 1, n+1) {
        if (vis[find_set(i)]) continue;
        if (cycle[find_set(i)]) {
            if (get_size(i) > 2) {
                mn_ans++;
                mx_ans++;
            }
        } else {
            if (status) {
                mx_ans++;
            } else {
                mn_ans++;
                mx_ans++;
                status = true;
            }
        }

        vis[find_set(i)] = true;
    }

    cout << mn_ans << ' ' << mx_ans << endl;

    rep(i, 0, n+1) {
        parent[i] = 0;
        cycle[i] = false;
        A[i] = 0;
        siz[i] = 0;
    };

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