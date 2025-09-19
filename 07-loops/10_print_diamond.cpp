#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    // print upper
    for (int level = 0; level < n; ++level) {
        for (int space = 0; space < (n - level - 1); ++space) {
            cout << ' ';
        }

        for (int star = 0; star < (2 * level + 1); ++star) {
            cout << '*';
        }

        cout << '\n';
    }

    // print lower
    for (int level = n - 1; level >= 0; --level) {
        for (int space = 0; space < (n - level - 1); ++space) {
            cout << ' ';
        }

        for (int star = 0; star < (2 * level + 1); ++star) {
            cout << '*';
        }
        
        cout << '\n';
    }

    return 0;
}