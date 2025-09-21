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

    if (word.size() == test_substr.size() and word != test_substr) {
        cout << FAIL_MSG << '\n';
        return 0;
    }

    for (int i = 0; i <= word.size() - test_substr.size(); ++i) {
        if (word[i] != test_substr.front())
            continue;

        bool is_valid_substr = true;

        for (int j = 1; j < test_substr.size(); ++j) {
            if (word[i + j] != test_substr[j]) {
                is_valid_substr = false;
                break;
            }
        }

        if (is_valid_substr) {
            cout << SUCCESS_MSG << '\n';
            return 0;
        }
    }

    cout << FAIL_MSG << '\n';

    return 0;
}