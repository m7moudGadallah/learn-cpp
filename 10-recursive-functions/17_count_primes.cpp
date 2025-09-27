#include <iostream>

using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }

    return true;
}

int count_primes(int start, int end) {
    if (start > end) return 0;

    return is_prime(start) + count_primes(start + 1, end);
}

int main() {
    int start, end;
    cin >> start >> end;

    cout << count_primes(start, end) << '\n';

    return 0;
}