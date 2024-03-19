#include<iostream>
using namespace std;

#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef pair<int,int> pii;
string alpha = "abcdefghijklmnopqrstuvwxyz";

pii good_string(int start, int end, int char_index,const string& s) {
    

    // 
    int mid = start + (end-start)/2;
    int cnt = 0;
    for (int i = start; i < end; i++) if (s[i] != alpha[char_index]) cnt++;

    if (end-start == 1) {
        if (s[start] == alpha[char_index+1]) return make_pair(cnt, 0);
        else return make_pair(cnt, 1);
    }

    const auto& left = good_string(start, mid, char_index+1, s);
    const auto& right = good_string(mid, end, char_index+1, s);

    return make_pair(cnt, min(left.first + right.second, left.second + right.first));
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s.size()==1){
        if (s[0]=='a') cout << "0\n";
        else cout << "1\n";
        return;
    }
    const auto& ans1 = good_string(0, s.size()/2, 0, s);
    const auto& ans2 = good_string(s.size()/2, s.size(), 0, s);
    cout << min(ans1.first+ans2.second, ans1.second+ans2.first) << endl;
}


int main() {
    ghaderi
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}