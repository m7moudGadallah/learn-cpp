#include<bits/stdc++.h>

using namespace std;

inline int calc_num_of_digits(int num) {
    if (num == 0) return 1;

    if (num < 0) num *= -1;

    int digits = 0;

    while (num) {
        ++digits;
        num /= 10;
    }

    return digits;
}

int main() {
    int num;

    cin >> num;

    cout << calc_num_of_digits(num) << "\n";

    return 0;
}