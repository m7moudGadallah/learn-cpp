#include <iostream>

using namespace std;

int main() {
    int k, n;

    cin >> k >> n;

    int arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int running_sum = 0,
        left_idx = 0,
        max_left_idx = 0,
        max_right_idx = 0,
        max_sum = INT_MIN;

    for (int i = 0; i < n; ++i) {
        if (i - left_idx == k) {
            if (running_sum > max_sum) {
                max_sum = running_sum;
                max_left_idx = left_idx;
                max_right_idx = i - 1;
            }
            ++left_idx;
        }
        running_sum += arr[i];
    }

    if (running_sum > max_sum) {
        max_sum = running_sum;
        max_left_idx = left_idx;
        max_right_idx = n - 1;
    }

    cout << max_left_idx << " " << max_right_idx << " " << max_sum << '\n';

    return 0;
}