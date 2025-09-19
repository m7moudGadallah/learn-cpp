#include <iostream>

using namespace std;

inline bool is_no(string const str) {
    if (str.size() != 2 or (tolower(str[0]) == tolower(str[1]))) return false;

    auto is_valid_char = [&](const int idx)->const bool {
        return (str[idx] == 'N'
            or str[idx] == 'n'
            or str[idx] == 'O'
            or str[idx] == 'o');
        };

    return is_valid_char(0) and is_valid_char(1);
}

int main() {
    int n;
    string str;

    cin >> n;

    while (n--) {
        cin >> str;

        if (is_no(str)) {
            cout << str << ' ';
        }
    }

    cout << '\n';

    return 0;
}