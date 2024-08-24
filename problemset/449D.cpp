// https://codeforces.com/problemset/problem/449/D

#include<bits/stdc++.h>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define int long long int
#define pii pair<int,int>
#define vi vector<int>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORS(i, a, b, c) for (int i = a; i < b; i += c)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)
#define EACH(e, a) for (auto& e : a)
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define endl "\n"
#define _MOD (1000000007)
#define MOD(n) (((n % _MOD) + _MOD) % _MOD)
#define ONLINE_JUDGE

int n, x;
const int M = 20, N = 1 << M;
int sup[N]{};
void makeSup(){
    for(int i = 0; i < M; i++) for(int mask = 0; mask < N; mask++)
        if((mask >> i) & 1) sup[mask ^ (1 << i)] += sup[mask], sup[mask ^ (1 << i)] = MOD(sup[mask ^ (1 << i)]);
}
 
void revSup(){
    for(int i = M - 1; i >= 0; i--) for(int mask = 0; mask < N; mask++)
        if((mask >> i) & 1) sup[mask ^ (1 << i)] -= sup[mask], sup[mask ^ (1 << i)] = MOD(sup[mask ^ (1 << i)]);
}

int power(const int n, const int p){
    // Base case:
    if(p == 0) return 1;
    // Recursive case:
    int ans{power(n, p / 2)};
    ans *= ans;
    ans = MOD(ans);
    if(p & 1) ans *= n;
    return MOD(ans);
}

void solve() {
    cin >> n;
    FOR(i,0,n) cin >> x, sup[x]++;
    makeSup();
    FOR(mask,0,N) sup[mask] = MOD(power(2, sup[mask]) - 1);
    revSup();
    cout << sup[0];
}



int32_t main() {
    ghaderi
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
