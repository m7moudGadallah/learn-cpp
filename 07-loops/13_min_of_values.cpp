#include <iostream>

using namespace std;

int main() {
    int test_cases, n, num, mn;

    cin >> test_cases;

    while (test_cases--) {
        cin >> n;
        mn = INT_MAX;

        while (n--) {
            cin >> num;
            mn = min(mn, num);
        }

        cout << mn << '\n';
    }

    return 0;
}