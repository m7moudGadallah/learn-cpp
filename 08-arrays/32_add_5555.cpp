#include<iostream>
#include<string>
#include <algorithm> 

using namespace std;

int main() {
    const string added_num = "5555";

    string str_num;
    cin >> str_num;

    int carry = 0;

    string ans = "";

    int i = str_num.size() - 1,
        j = added_num.size() - 1;
    for (;i >= 0 and j >= 0; --i, --j) {
        int digit = (str_num[i] - '0') + (added_num[j] - '0') + carry;
        carry = digit / 10;
        digit %= 10;
        ans.push_back(digit + '0');
    }


    while (j >= 0) {
        int digit = (added_num[j] - '0') + carry;
        carry = digit / 10;
        digit %= 10;
        ans.push_back(digit + '0');
        --j;
    }

    while (i >= 0) {
        int digit = (str_num[i] - '0') + carry;
        carry = digit / 10;
        digit %= 10;
        ans.push_back(digit + '0');
        --i;
    }


    if (carry) {
        ans.push_back(carry + '0');
    }

    reverse(ans.begin(), ans.end());

    cout << ans << '\n';

    return 0;
}