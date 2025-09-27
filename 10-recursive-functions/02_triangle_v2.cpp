#include <iostream>

using namespace std;

void display_triangle(int levels) {
    if (levels < 1) return;

    display_triangle(levels - 1);

    for (int i = 0; i < levels; ++i) {
        cout << '*';
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;

    display_triangle(n);

    return 0;
}