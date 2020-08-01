#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void swap(string& s, int x, int y) {
    char tmp = s.at(x);
    s.at(x) = s.at(y);
    s.at(y) = tmp;
}

void permute(string& s, int l, int r) {
    if (l==r) cout << s << " ";
    else {
        for (int i=l; i<=r; i++) {
            swap(s, l, i);
            permute(s, l+1, r);
            swap(s, l, i);
        }
    }
}

int main() {
    string s;
    cout << "input: ";
    cin >> s;

    // Answer 1: utilized next_permutation()
    cout << "ans 1: { ";
    do {
        for (int i=0; i<int(s.size()); i++) {
            cout << s.at(i);
        }
        cout << " ";
    } while(next_permutation(s.begin(), s.end()));
    cout << "}\n";

    // Answer 2: with recursive function
    cout << "ans 2: { ";
    permute(s, 0, s.size()-1);
    cout << "}\n";
    return 0;
}