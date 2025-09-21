#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;

    if (!str.size()) {
        cout << '\n';
        return 0;
    }

    char last_char = str.front();
    int last_char_count = 1;

    for (int i = 1; i < str.size(); ++i) {
        if (str[i] != last_char) {
            cout << last_char << last_char_count << '_';
            last_char_count = 0; // reset
        }

        last_char = str[i];
        ++last_char_count;
    }

    cout << last_char << last_char_count << '\n';

    return 0;
}