#include <iostream>

using namespace std;

int main() {
    int x, y;

    cin >> x >> y;

    while (x <= y) {
        cout << x++ << "\n";
    }

    return 0;
}