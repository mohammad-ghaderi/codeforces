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
const int N = 1001;
int n, m;
int mp[N][N];
int mn[N][N], mx[N][N];


void solve() {
    cin >> n >> m;
    
    rep(i, 0, n) rep(j, 0, m) mn[i][j] = 5000, mx[i][j] = -5000;

    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> mp[i][j];
            if (i == 0 and j == 0) {
                mn[i][j] = mp[i][j];
                mx[i][j] = mp[i][j];
            } else if (i == 0) {
                mn[i][j] = mn[i][j-1] + mp[i][j];
                mx[i][j] = mx[i][j-1] + mp[i][j];
            } else if (j == 0) {
                mn[i][j] = mn[i-1][j] + mp[i][j];
                mx[i][j] = mx[i-1][j] + mp[i][j];
            } else {
                mn[i][j] = min(mn[i][j-1], mn[i-1][j]) + mp[i][j];
                mx[i][j] = max(mx[i][j-1], mx[i-1][j]) + mp[i][j];
            }
        }
    }
    if ((n+m)%2==0) cout << "NO\n";
    else cout << (mn[n-1][m-1]<=0 and mx[n-1][m-1] >= 0?"YES\n":"NO\n");
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