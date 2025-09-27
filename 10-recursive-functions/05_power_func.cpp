#include <iostream>

using namespace std;

long my_pow(const int& base, int p) {
    if (p == 0) {
        return 1;
    }

    long long tmp = my_pow(base, p / 2);

    return (p % 2 == 0) ? tmp * tmp : tmp * tmp * base;
}

int main() {
    int base, p;
    cin >> base >> p;

    cout << my_pow(base, p) << '\n';

    return 0;
}