#include <iostream>

using namespace std;

int main() {
    const string SUCCESS_MSG = "YES";
    const string FAIL_MSG = "NO";

    string word, test_subsequence;
    cin >> word >> test_subsequence;

    if (word.size() < test_subsequence.size()) {
        cout << FAIL_MSG << '\n';
        return 0;
    }

    int sub_itr = 0;
    for (int word_itr = 0; word_itr < word.size() and sub_itr < test_subsequence.size(); ++word_itr) {
        sub_itr += (word[word_itr] == test_subsequence[sub_itr]);
    }

    cout << (sub_itr >= test_subsequence.size() ? SUCCESS_MSG : FAIL_MSG) << '\n';

    return 0;
}