#include <iostream>
using namespace std;

string one[] = {"zero ", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ",
"ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "};
string ten[] = {"", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};

string num2words(long long n, long long m, string s) {
    string str="";
    if (n>19) {
        if (n%10==0) str += ten[n/10];
        else str += ten[n/10] + one[n%10];
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

string convert(int n) {
    string str="";
    str += num2words((n/100)%10, n, "hundred "); // 100~999
    str += num2words(n%100, n, ""); // 0~99
    return str;
}

int main() {
    int n;
    string ans;
    cout << "N: ";
    cin >> n;
    ans = convert(n);
    printf("Answer: %s\n", ans.c_str());
}