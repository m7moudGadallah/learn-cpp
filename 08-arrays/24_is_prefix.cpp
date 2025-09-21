#include <iostream>

using namespace std;

int main() {
    const string SUCCESS_MSG = "YES";
    const string FAIL_MSG = "NO";

    string word, prefix_test;

    cin >> word >> prefix_test;


    if (word.size() < prefix_test.size()) {
        cout << FAIL_MSG << '\n';
        return 0;
    }

    if (word.size() == prefix_test.size() and word != prefix_test) {
        cout << FAIL_MSG << '\n';
        return 0;
    }

    for (int i = 0; i < prefix_test.size(); ++i) {
        if (word[i] != prefix_test[i]) {
            cout << FAIL_MSG << '\n';
            return 0;
        }
    }

    cout << SUCCESS_MSG << '\n';

    return 0;
}