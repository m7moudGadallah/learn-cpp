#include <iostream>

using namespace std;

int suffix_sum(int arr[], int size, int k) {
    if (k < 1 or k > size) return 0;

    if (k == 1) return arr[size - 1];

    return arr[size - 1] + suffix_sum(arr, size - 1, k - 1);
}

int main() {
    int n, k;
    cin >> n;

    int arr[n];
    for (auto& ele : arr) {
        cin >> ele;
    }

    cin >> k;

    cout << suffix_sum(arr, n, k) << '\n';

    return 0;
}