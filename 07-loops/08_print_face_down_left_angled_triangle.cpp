#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int level = n; level > 0; --level) {
        for (int star = 0; star < level; ++star) {
            cout << '*';
        }

        cout << '\n';
    }

    return 0;
}