#include<iostream>
#include<vector>
using namespace std;
typedef vector<int> vi;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

void solve() {
    int n, penalty = 0, x = 0, y = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vi first, second;
    for (int i = 0; i < n; i++) {
        if (x == 0 || y == 0) {
            if (x == 0 || first.at(x-1) >= a[i]) first.push_back(a[i]),x++;
            else second.push_back(a[i]), y++;
        } else {
            bool bf = a[i] > first.at(x-1);
            bool bs = a[i] > second.at(y-1);
            if (bf&&bs){
                if (first.at(x-1) > second.at(y-1)) second.push_back(a[i]), y++;
                else first.push_back(a[i]), x++;
                penalty++;
            } else if (bf) second.push_back(a[i]), y++;
            else if (bs) first.push_back(a[i]), x++;
            else {
                if (first.at(x-1) > second.at(y-1)) second.push_back(a[i]), y++;
                else first.push_back(a[i]), x++;
            }
        }
    }
    cout << penalty << endl;
}

int main () {
    ghaderi;

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}