#include <iostream>
using namespace std;

long long ans1(long long n, long long &f) {
    long long f2;
    long long ans=0;
    for (long long i=1; i<=n; i++) f*=i; // calc factorial of n
    f2=f;
    while((f2%10)==0) {
        ans++;
        f2/=10;
    }
    return ans;
}

long long ans2(long long n) {
    long long ans=0;
    for (long long denom=5; denom<=n; denom*=5) {
        ans += n/denom;
    }
    return ans;
}

int main() {
    long long n, ans;
    long long f=1;
    cout << "N: ";
    cin >> n;
    ans = ans1(n, f);
    printf("Answer1: [%lld] (factorial of %lld is %lld)\n", ans, n, f);
    ans = ans2(n);
    printf("Answer2: [%lld]\n", ans);
}