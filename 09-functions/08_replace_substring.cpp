#include <iostream>

using namespace std;

bool starts_with(const string& input, const string& pattern, const int& pos) {
    for (int j = 0; j < pattern.size() and pos + j < input.size(); ++j) {
        if (input[pos + j] != pattern[j]) {
            return false;
        }
    }

    return true;
}

string replace_str(const string& input, const string& pattern, const string& to) {
    string ans = "";

    for (int i = 0; i < input.size(); ++i) {
        if (!starts_with(input, pattern, i)) {
            ans.push_back(input[i]);
        }
        else {
            ans.append(to);
            i += pattern.size() - 1;
        }

    }

    return ans;
}

int main() {
    string input, pattern, to;
    cin >> input >> pattern >> to;

    cout << replace_str(input, pattern, to) << '\n';

    return 0;
}