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
    int n, m;
    cin >> n >> m;

    bool vis1[n]{}, vis2[n]{}, ans[n]{};
    vector<pair<int, bool>> e[n]{};

    int u, v;
    string s;
    rep(i, 0, m) {
        cin >> u >> v >> s;
        u--; v--;
        if (s == "imposter") {
            e[u].push_back({v, false});
            e[v].push_back({u, false});
        } else {
            e[u].push_back({v, true});
            e[v].push_back({u, true});
        }
    }

    queue<int> q{};
    int answer = 0;

    rep(i, 0, n) {
        if (vis1[i]) continue;
        if (e[i].size() == 0) {
            answer++;
            continue;
        }
        q.push(i);
        ans[i] = true;
        vis1[i] = true;

        int an = 0;
        int mx = 0;

        while (!q.empty()) {
            int a = q.front();
            q.pop();

            if (ans[a]) an++;

            for (auto x: e[a]) {
                if (vis1[x.first]) {
                    bool t = ans[a]?x.second:!x.second;
                    if (t != ans[x.first]) return false;
                } else {
                    ans[x.first] = ans[a]?x.second:!x.second;
                    vis1[x.first] = true;
                    q.push(x.first);
                }
            }
        }
        mx = an;
        an = 0;

        q.push(i);
        ans[i] = false;
        vis2[i] = true;

        while (!q.empty()) {
            int a = q.front();
            q.pop();

            if (ans[a]) an++;

            for (auto x: e[a]) {
                if (vis2[x.first]) {
                    bool t = ans[a]?x.second:!x.second;
                    if (t != ans[x.first]) return false;
                } else {
                    ans[x.first] = ans[a]?x.second:!x.second;
                    vis2[x.first] = true;
                    q.push(x.first);
                }
            }
        }

        mx = max(mx, an);
        answer += mx;
    }

    cout << answer << endl;
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
    while (t--) if (!solve()) cout << "-1\n";

    return 0;
}