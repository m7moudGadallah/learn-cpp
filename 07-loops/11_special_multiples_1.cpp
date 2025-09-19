#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i <= n; ++i) {
        if (i % 8 == 0 or (i % 3 == 0 && i % 4 == 0))
            cout << i << ' ';
    }
    cout << '\n';

    return 0;
}