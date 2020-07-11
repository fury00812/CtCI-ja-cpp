#include<iostream>
#include<vector>
using namespace std;

int search(vector<string> strings, string str, int first, int last) {
    if (first>last) return -1;
    int mid = (last+first)/2;

    /* midが空文字列なら最も近い空でない文字列を探す */
    if (strings.at(mid)=="") {
        int left = mid-1;
        int right = mid+1;
        while (true) {
            if (left<first && right>last) return -1;
            else if (right <= last && strings.at(right)!="") {
                mid = right;
                break;
            }
            else if (left >= first && strings.at(left)!="") {
                mid = left;
                break;
            }
            right++;
            left--;
        }
    }

    /* 通常の二分探索 */
    if (str==strings.at(mid)) return mid;
    else if (strings.at(mid) < str) return search(strings, str, mid+1, last);
    else return search(strings, str, first, mid-1);
}

int main() {
    vector <string> strings = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    vector <string> q = {"ball", "dad", "at", "car", "wan"};
    cout << "Array: {";
    for (int i=0; i<int(strings.size())-1; i++) {
        cout << "\"" << strings.at(i) << "\", ";
    }
    cout << "\"" << strings.at(strings.size()-1) << "\"}\n";
    for (int i=0; i<int(q.size()); i++) cout << q.at(i) << ": " << search(strings, q.at(i), 0, strings.size()-1) << endl;
}