#include <iostream>

using namespace std;

int main() {
    int n, num, prev;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        prev = num;
        cin >> num;

        if (i == 0 or num != prev) cout << num << ' ';
    }
    cout << '\n';
}