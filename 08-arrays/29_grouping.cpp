#include<iostream>

using namespace std;

int main() {
    string str;
    cin >> str;

    if (!str.size()) {
        cout << '\n';
        return 0;
    }

    cout << str.front();

    for (int i = 1; i < str.size(); ++i) {
        if (str[i] != str[i - 1]) {
            cout << ' ';
        }
        cout << str[i];
    }
    cout << '\n';

    return 0;
}