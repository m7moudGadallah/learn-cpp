#include <iostream>

using namespace std;

int calc_prefix_sum(int arr[], int size, const int& k) {
    if (size < 1) {
        return 0;
    }

    // just for optimization to avoid non-useful recurrence
    size = min(size, k);

    return arr[size - 1] + calc_prefix_sum(arr, size - 1, k);
}

int main() {
    int n, k;
    cin >> n;

    int arr[n];
    for (auto& ele : arr) {
        cin >> ele;
    }

    cin >> k;

    cout << calc_prefix_sum(arr, n, k) << '\n';
    return 0;
}