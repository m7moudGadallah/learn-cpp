#include <iostream>

using namespace std;

int main() {
    const string from = "abcdefghijklmnopqrstuvwxyz0123456789";
    const string to = "YZIMNESTODUAPWXHQFBRJKCGVL!@#$%^&*()";

    const int CHAR_MAP_SIZE = 150;
    int char_map[CHAR_MAP_SIZE]{ 0 };

    for (int i = 0; i < from.size(); ++i) {
        char_map[from[i]] = i;
    }

    string inp_str;

    cin >> inp_str;

    string out_str = inp_str;

    // Transform out_str
    for (int i = 0; i < out_str.size(); ++i) {
        const char& normalized_char = tolower(out_str[i]);
        out_str[i] = to[char_map[normalized_char]];
    }

    cout << out_str << '\n';

    return 0;
}