#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;

        for (int i = 0; i < max(str1.size(), str2.size()); ++i) {
            if (i < str1.size()) cout << str1[i];
            if (i < str2.size()) cout << str2[i];
        }
        cout << '\n';
    }

    return 0;
}