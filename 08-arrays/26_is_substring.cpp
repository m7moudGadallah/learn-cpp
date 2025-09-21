#include <iostream>

using namespace std;

int main() {
    const string SUCCESS_MSG = "YES";
    const string FAIL_MSG = "NO";

    string word, test_substr;
    cin >> word >> test_substr;

    if (word.size() < test_substr.size()) {
        cout << FAIL_MSG << '\n';
        return 0;
    }

    bool is_valid_substr = false;

    for (int i = 0; i <= word.size() - test_substr.size() and !is_valid_substr; ++i) {
        is_valid_substr = true; // assume it will be valid

        for (int j = 1; is_valid_substr and j < test_substr.size(); ++j) {
            is_valid_substr = (word[i + j] == test_substr[j]);
        }
    }

    cout << (is_valid_substr ? SUCCESS_MSG : FAIL_MSG) << '\n';

    return 0;
}