#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;

    const int NUM_OF_CHARS = 26;
    int freq[NUM_OF_CHARS]{ 0 };

    for (const auto ch : str) {
        freq[tolower(ch) - 'a']++;
    }

    for (int i = 0; i < NUM_OF_CHARS; ++i) {
        if (freq[i]) {
            cout << char('a' + i) << " : " << freq[i] << '\n';
        }
    }

    return 0;
}