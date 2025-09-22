#include <iostream>

using namespace std;

int main() {
    const string SUCCESS_MSG = "YES";
    const string FAIL_MSG = "NO";
    const int LESS_THAN_CODE = -1;
    const int EQUAL_CODE = 0;
    const int GREATER_THAN_CODE = 1;

    string str1, str2;
    cin >> str1 >> str2;

    int comparison = EQUAL_CODE;

    for (int i = 0; i < min(str1.size(), str2.size()) and comparison == EQUAL_CODE; ++i) {
        if (str1[i] == str2[i]) continue;

        comparison = (str1[i] < str2[i]) ? LESS_THAN_CODE : GREATER_THAN_CODE;
    }


    if (comparison == EQUAL_CODE and str1.size() > str2.size())
        cout << FAIL_MSG << '\n';
    else
        cout << ((comparison == GREATER_THAN_CODE) ? FAIL_MSG : SUCCESS_MSG) << '\n';

    return 0;
}