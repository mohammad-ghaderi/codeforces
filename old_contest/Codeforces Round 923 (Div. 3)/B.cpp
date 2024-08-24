#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

void solve() {
    string letters = "abcdefghijklmnopqrstuvwxyz";

    int n, start = 0;
    cin >> n;
    int numbs[n];
    char chars[n];
    bool used[n]{false};
    
    for (int i = 0; i < n; i++) 
        cin >> numbs[i];

    for (int i = 0; i < n; i++) {
        if (numbs[i] == 0){
            chars[i] = letters[start++];
            continue;
        } 
        for (int j = i-1; j >= 0; j--) {
            if (numbs[j] == numbs[i]-1 && !used[j]){
                used[j] = true;
                chars[i] = chars[j];
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << chars[i];
    cout << endl;
}

int main () {
    ghaderi;

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}