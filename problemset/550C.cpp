#include<bits/stdc++.h>
using namespace std;
#define ghaderi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int convert(char c,int z) {
    return z*(c - '0');
}

void solve() {
    string number;
    cin >> number;
    number = "00" + number;
    int new_num;

    for (int i = 0; i < number.size(); i++) {
        for (int j = i+1; j < number.size(); j++) {
            for (int k = j+1; k < number.size(); k++) {
                new_num = convert(number[i],100) + convert(number[j],10) + convert(number[k], 1);
                if (number[k]=='0') {
                    cout << "YES\n0";
                    return;
                } else if (new_num%8==0) {
                    cout << "YES\n";
                    cout << new_num;
                    return;
                }
            }
        }
    }
    cout << "NO";
    return;
}

int main() {
    ghaderi
    solve();
    return 0;
}