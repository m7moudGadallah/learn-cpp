#include <iostream>

using namespace std;

bool is_prefix(const string& word, const string& prefix, int start_pos = 0) {
    if (start_pos >= prefix.size()) return true;

    if (start_pos >= word.size()) return false;

    return (word[start_pos] == prefix[start_pos]) and is_prefix(word, prefix, start_pos + 1);
}

int main() {
    string word, prefix;
    cin >> word >> prefix;

    cout << is_prefix(word, prefix) << '\n';
    return 0;
}