#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
typedef long long ll;

struct Col {
    ll Number{}, Keep{}, Delete{};
};

int main() {
    ghaderi
    ll n, num;
    cin >> n;
    vector<Col> a{};
    ll rep[200000]{0};
    
    for (ll i = 0; i < n; i++) {
        cin >> num;
        if (rep[num]==0) a.push_back({num, 0, 0});
        rep[num]++;
    }

    sort(a.begin(), a.end(), [](const auto& a, const auto& b){ return a.Number < b.Number;});

    ll len = a.size();
    for (ll i = len - 1; i >= 0; i--) {
        auto& curr = a.at(i);
        if (i == len - 1) {
            curr.Keep = rep[curr.Number] * curr.Number;
            continue;
        }
        const auto& nxt = a.at(i+1);
        if (nxt.Number - curr.Number == 1) curr.Keep = nxt.Delete + rep[curr.Number] * curr.Number;
        else curr.Keep = max(nxt.Keep + rep[curr.Number] * curr.Number, nxt.Delete + rep[curr.Number] * curr.Number);
        curr.Delete = max(nxt.Delete, nxt.Keep);
    }
    
    cout << max(a.at(0).Delete, a.at(0).Keep);
    
    
    return 0;
}