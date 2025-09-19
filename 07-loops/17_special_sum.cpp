#include <iostream>

using namespace std;

inline long calc_pow(int num, int pow) {
    if (pow < 1) return 1;

    long res = 1;

    while (pow--) {
        res *= num;
    }

    return res;
}

inline void exec_test_case() {
    int n, num;
    long sum = 0;

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> num;
        sum += calc_pow(num, i);
    }

    cout << sum << '\n';
}

int main() {
    int test_cases, n, num;

    cin >> test_cases;

    while (test_cases--)
        exec_test_case();

    return 0;
}