#include <iostream>

using namespace std;

int main() {
    int test_cases, n;

    cin >> test_cases;

    while (test_cases--) {
        cin >> n;

        if (n <= 0) return 0;

        int arr[n]{ 0 };

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        long ans = INT_MAX;
        int min_left = arr[0];

        for (int i = 1; i < n; ++i) {
            ans = min<long>(ans, ((arr[i] + i) + min_left));
            min_left = min(min_left, (arr[i] - i));
        }

        cout << ans << '\n';
    }

    return 0;
}