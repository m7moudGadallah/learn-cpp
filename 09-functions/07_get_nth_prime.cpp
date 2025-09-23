#include <iostream>

using namespace std;

inline bool is_prime(int num) {
    if (num < 2) return false;

    for (int n = 2; n * n <= num; ++n) {
        if (num % n == 0) {
            return false;
        }
    }

    return true;
}

inline int nth_prime(int n) {
    int ans = -1;

    for (int i = 2; n; ++i) {
        if (is_prime(i)) {
            --n;
            ans = i;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    cout << nth_prime(n) << '\n';

    return 0;
}