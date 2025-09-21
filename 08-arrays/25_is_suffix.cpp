#include <iostream>

using namespace std;

int main() {
    const string SUCCESS_MSG = "YES";
    const string FAIL_MSG = "NO";

    string word, test_suffix;
    cin >> word >> test_suffix;

    if (word.size() < test_suffix.size()) {
        cout << FAIL_MSG << '\n';
        return 0;
    }

    if (word.size() == test_suffix.size() and word != test_suffix) {
        cout << FAIL_MSG << '\n';
        return 0;
    }

    for (int i = 1; i <= test_suffix.size(); ++i) {
        if (word[word.size() - i] != test_suffix[test_suffix.size() - i]) {
            cout << FAIL_MSG << '\n';
            return 0;
        }
    }

    cout << SUCCESS_MSG << '\n';

    return 0;
}