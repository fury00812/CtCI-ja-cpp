#include <bits/stdc++.h>
#include <vector>
using namespace std;

int ans1(int amount) {
    int ways=0;
    for (int i=0; i*25<=amount; i++) {
        for (int j=0; j*10<=amount; j++) {
            for (int k=0; k*5<=amount; k++) {
                if ((i*25+j*10+k*5)<=amount) ways++;
            }
        }
    }
    return ways;
}

int ans2(int amount, vector<int> denoms, int index, vector<vector<int>> map) {
//    if (map.at(amount).at(index)>0) return map.at(amount).at(index)>0; // メモ化
    if (index>=(int)denoms.size()-1) return 1; // 終了条件
    
    int denomAmount = denoms.at(index);
    int ways = 0;
    for (int i=0; (i*denomAmount)<=amount; i++) {
        int amountRemaining = amount-i*denomAmount;
        ways += ans2(amountRemaining, denoms, index+1, map);
    }
//    map.at(amount).at(index) = ways;
    return ways;
}

int main() {
    int n;
    cout << "(input) n: ";
    cin >> n;

    // Answer 1: for loop (O(N^3))
    cout << "ans 1: " << ans1(n) << endl;

    // Answer 2: recursion (O(N^3))
    vector <int> denoms = {25, 10, 5, 1};
    vector<vector<int>> map(n+1, vector<int>(denoms.size(), 0));
    cout << "ans 2: " << ans2(n, denoms, 0, map) << endl;
}