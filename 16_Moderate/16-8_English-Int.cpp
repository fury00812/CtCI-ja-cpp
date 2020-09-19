#include <iostream>
using namespace std;

string one[] = {"zero ", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ",
"ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "};
string ten[] = {"", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};

string num2words(long long n, long long m, string s) {
    string str="";
    if (n>19 && n<=99) {
        if (n%10==0) str += ten[n/10];
        else str += ten[n/10] + one[n%10];
    }
    else if (n>99) {
        str += num2words((n/100)%10, m, "hundred ");
    }
    else {
        if (m<=99) { // "zero" 
            if (s=="") str += one[n];
        }
        else if (n) str += one[n];
    }
    if (n) str += s;
    return str;
}

string convert(long long n) {
    string str="";
    // short scale
    str += num2words((n/1000000000000000000)%1000, n, "quintillion "); // 10^18 <= n < 10^21
    str += num2words((n/1000000000000000)%1000, n, "quadrillion "); // 10^15 <= n < 10^18
    str += num2words((n/1000000000000)%1000, n, "trillion "); // 10^12 <= n < 10^15
    str += num2words((n/1000000000)%1000, n, "billion "); // 10^9 <= n < 10^12
    str += num2words((n/1000000)%1000, n, "million "); // 10^6 <= n < 10^9
    str += num2words((n/1000)%1000, n, "thousand "); // 10^3 <= n < 10^6
    str += num2words((n/100)%10, n, "hundred "); // 10^2 <= n < 10^3
    str += num2words(n%100, n, ""); // 10^0 (and zero) <= n < 10^2
    return str;
}

int main() {
    long long n;
    string ans;
    cout << "N: ";
    cin >> n;
    ans = convert(n);
    printf("Answer: %s\n", ans.c_str());
}