#include <vector>
#include <iostream>
using namespace std;

int ans1(int large, int small) {
    if (small==0) return 0;
    if (small>0) return (large + ans1(large, small-1)) ;
    else return -ans1(large, -small);
}

int ans2(int large, int small, vector<int> &dp) {
    if (small==0) return 0;
    else if (small==1)  return large;
    else if (small<0) return -ans2(large, -small, dp);

    if (dp[small]!=-1) return dp[small];
    int s = small >> 1; // 2で割る
    int side1 = ans2(large, s, dp);
    int side2 = 0;
    if (small%2==0) side2 = side1;
    else side2 = ans2(large, small-s, dp);
    dp[small] = side1+side2;
    return side1+side2;
}

int main() {
    int a, b;
    cout << "input: a b = ";
    cin >> a >> b;

    int l = a>b ? a:b;
    int s = a<b ? a:b;

    // Answer 1: naive recursion
    cout << "ans 1: a*b = " << ans1(l,s) << "\n";

    // Answer 2: CtCI's solution 2
    vector<int> dp(abs(s)+1, -1);
    cout << "ans 2: a*b = " << ans2(l,s,dp) << "\n";
}