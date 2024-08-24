#include<bits/stdc++.h>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORS(i, a, b, c) for (int i = a; i < b; i += c)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)
#define EACH(e, a) for (auto& e : a)
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define endl "\n"

#define ONLINE_JUDGE
int n;
string s;

bool ch(int x, int i) {
    bool f = false;
    int nx = i;
    int end = n/i;
    if (x != 0) end--;
    FOR(k,0,end){
        if (nx == n) break;
        FOR(j,0,i) {
            if (s[x+j] != s[nx+j]) {
                if (f) return false;
                f = true;
            }
        }
        nx += i;
    }

    if (x!=0) {
        FOR(j,0,i) {
            if (s[x+j] != s[0+j]) {
                if (f) return false;
                f = true;
            }
        }
    }
    return true;
}

int check() {
    FOR(i,1,n+1) {
        if (n%i!=0) continue;
        if (ch(0,i) or ch(i,i)) return i;
    }
    return n;
}

void solve() {
    cin >> n;
    cin >> s;
    cout << check() << endl;
}



int main() {
    ghaderi
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
