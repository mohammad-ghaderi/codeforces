#include<iostream>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#include<queue>
#include<unordered_map>

void solve() {
    int n;
    cin >> n;
    char trump;
    cin >> trump;
    
    unordered_map<char,priority_queue<int>> cards{};
    string card;
    string names = "CDHS";
    int cnt = 0;
    for (int i = 0; i < 2*n; i++) {
        cin >> card;
        auto iter = cards.find(card[1]);
        if (iter == cards.end()) cards[card[1]] = {};
        cards[card[1]].push(card[0]-'0');
    }
    
    for (const char c: names) 
    if (c != trump and cards[c].size()%2 == 1) 
        cnt++;

    if (cnt>cards[trump].size() or (cards[trump].size()-cnt)%2 == 1) {cout << "IMPOSSIBLE\n"; return;}
    
    for (const char c: names) {
        if (c == trump) continue;
        while (cards[c].size() >= 2) {
            const auto second = cards[c].top();
            cards[c].pop();
            const auto first = cards[c].top();
            cards[c].pop();
            cout << first << c << " " << second << c << '\n';
        }
        if (cards[c].size() == 1) {
            cout << cards[c].top() << c << " " << cards[trump].top() << trump << '\n';
            cards[trump].pop();
        }
    }
    while (cards[trump].size() > 1) {
        const auto second = cards[trump].top();
        cards[trump].pop();
        const auto first = cards[trump].top();
        cards[trump].pop();
        cout << first << trump << " " << second << trump << '\n';
    }
    
}

int main() {
    ghaderi
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}