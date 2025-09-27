#include <iostream>

using namespace std;

void display_triangle(int levels) {
    if (levels < 1) return;

    for (int i = 0;i < levels; ++i) {
        cout << '*';
    }
    cout << '\n';

    display_triangle(levels - 1);
}

int main() {
    int n;
    cin >> n;

    display_triangle(n);

    cout << '\n';
}