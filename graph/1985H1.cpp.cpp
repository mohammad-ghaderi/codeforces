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
const int SIZE = 1e6+5;

int n, m;
vector<pair<int,int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<string> s{};

vector<vector<int>> islands{};
int island_size[SIZE]{};
int color = 0;

bool check(int i, int j) { 
    bool an =  !(i < 0 or j < 0 or i == n or j == m or s[i][j] == '.'); 
    return an;
}

void dfs(int i, int j) {
    if (!check(i, j) or islands[i][j]) return;
    islands[i][j] = color;
    island_size[color]++;

    for (auto dir: directions) {
        dfs(i + dir.ff, j + dir.ss);
    }
}

void solve() {
    cin >> n >> m;
    s.resize(n);
    islands.clear();
    islands.resize(n, vector<int>(m, 0));
    rep(i, 0, n) cin >> s[i];

    color = 0;

    rep(i, 0, n) {
         rep(j, 0, m) {
            if (!islands[i][j] and s[i][j] == '#') {
                color++;
                dfs(i, j);
            }
        }
    }

    int ans = 0;

    set<int> st{};

    rep(i, 0, n) {
        int cnt = 0;
        rep(j, 0, m) {
            // for each row we should find max
            for (auto dir: directions) {
                if (check(i + dir.ff, j + dir.ss)) {
                    st.insert(islands[i + dir.ff][j + dir.ss]);
                }
            }
            if (s[i][j] == '#') {
                st.insert(islands[i][j]);
            } 
            cnt += (s[i][j] == '.');
        }

        for (auto x: st) cnt += island_size[x];
        ans = max(ans, cnt);
        st.clear();
    }


    rep(j, 0, m) {
        int cnt = 0;
        rep(i, 0, n) {
            // for each row we should find max
            for (auto dir: directions) {
                if (check(i + dir.ff, j + dir.ss)) {
                    st.insert(islands[i + dir.ff][j + dir.ss]);
                }
            }
            if (s[i][j] == '#') {
                st.insert(islands[i][j]);
            }
            cnt += (s[i][j] == '.');
        }

        for (auto x: st) cnt += island_size[x];
        ans = max(ans, cnt);
        st.clear();
    }

    cout << ans << endl;

    rep(i, 0, color+1) island_size[i] = 0;
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