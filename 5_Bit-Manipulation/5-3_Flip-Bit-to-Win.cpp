#include<iostream>
using namespace std;

int flipBit(int a) {
    if (~a==0) return sizeof(int)*8;
    int currentLength = 0;
    int previousLength = 0;
    int maxLength = 1;
    while (a!=0) {
        if ((a&1)==1) currentLength++;
        else {
            if ((a&2)==0) previousLength=0;
            else previousLength=currentLength;
            currentLength=0;
        }
        maxLength = max(previousLength+currentLength+1, maxLength);
        a >>= 1;
    }
    return maxLength;
}

string getBit(int a) {
    string r="";
    while (a!=0) {
        r = to_string(a & 1)+r;
        a >>= 1;
    }
    return r;
}

int main() {
    int a;
    cin >> a;
    cout << getBit(a) << ": " << flipBit(a) << endl;
    // 1775 -> 11011101111: 8
    // 3791 -> 111011001111: 6
}