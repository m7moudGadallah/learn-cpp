#include <iostream>

using namespace std;

int len_of_3n_plus_1_seq(int n) {
    if (n == 1) {
        return 1;
    }

    return 1 + len_of_3n_plus_1_seq((n % 2 == 0) ? (n / 2) : (3 * n + 1));
}

int main() {
    int n;
    cin >> n;

    cout << len_of_3n_plus_1_seq(n) << '\n';

    return 0;
}