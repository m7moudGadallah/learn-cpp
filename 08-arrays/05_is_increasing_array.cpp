#include <iostream>

using namespace std;

int main() {
    int n, num = INT_MIN, prev = INT_MIN;

    cin >> n;

    while (n--) {
        prev = num;
        cin >> num;

        if (num < prev) {
            cout << "NO\n";
            return 0;
        };
    }

    cout << "YES\n";

    return 0;
}