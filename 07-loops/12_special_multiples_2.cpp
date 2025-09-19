#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; n; ++i) {
        if ((i % 3 == 0) and (i % 4 != 0)) {
            cout << i << ' ';
            --n;
        }
    }

    cout << '\n';

    return 0;
}