#include <iostream>

using namespace std;

void display_3n_plus_1_seq(int n) {
    if (n == 1) {
        cout << n << '\n';
        return;
    }

    cout << n << ' ';

    display_3n_plus_1_seq((n % 2 == 0) ? (n / 2) : (3 * n + 1));
}

int main() {
    int n;
    cin >> n;

    display_3n_plus_1_seq(n);

    return 0;
}