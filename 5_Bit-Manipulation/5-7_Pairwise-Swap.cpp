#include <iostream>
using namespace std;

int swapOddEvenBits(int x) {
    int even_mask = 0xAAAAAAAA; // 偶数マスク (101010..)
    int odd_mask  = 0x55555555; // 奇数マスク (010101..)
    return ((x&even_mask)>>1)|((x&odd_mask)<<1);
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
    int x;
    cin >> x;
    int ans = swapOddEvenBits(x);
    cout << x << "(" << getBit(x) << ") -> " << ans << "(" << getBit(ans) << ")\n";
    // 10(1010) -> 5(101)
    // 23(10111) -> 43(101011)
}