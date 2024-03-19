#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
int n, m, x;
unordered_set<int> s{};
bool d[1200][1200]{};

void check(int i, int x, vector<pair<int, char>>& rc) {
    if (x <= 0) x = n + x;
    if (i == m){ 
        s.emplace(x);
        return;
    }
    if (d[i][x]) return;

    if (rc[i].second != '1')
        check(i+1, (x+rc[i].first)%n, rc);
    if (rc[i].second != '0')
        check(i+1, (x-rc[i].first)%n, rc);
    
    d[i][x] = true;
}

void solve() {
    cin >> n >> m >> x;
    vector<pair<int, char>> rc(m);
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) 
            d[i][j] = false;
    
    s.clear();
    for (int i = 0; i < m; i++) {
        cin >> rc[i].first;
        cin >> rc[i].second;
    }
    
    check(0, x, rc);
    vector<int> v(s.begin(), s.end());
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << '\n';
    

}

int main() {
    ghaderi
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}