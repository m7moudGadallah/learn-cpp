#include <iostream>

using namespace std;

int main() {
    string num_str;

    cin >> num_str;

    int num = 0;

    for (const auto& digit : num_str) {
        num = (num * 10) + (digit - '0');
    }

    cout << num << ' ' << (num * 3) << '\n';

    return 0;
}