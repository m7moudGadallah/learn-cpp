#include <iostream>

using namespace std;

inline long sum_nums(const int end) {
    return ((long)end * (end + 1)) / 2;
}

int main() {
    int test_cases, num;

    cin >> test_cases;

    while (test_cases--) {
        cin >> num;
        cout << "Sum from 1 to " << num << " = " << sum_nums(num) << '\n';
    }
} 