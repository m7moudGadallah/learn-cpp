#include <iostream>

using namespace std;

int find_array_max(const int arr[], int size) {
    if (size < 1) {
        return INT_MIN;
    }

    return max(arr[size - 1], find_array_max(arr, size - 1));
}

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (auto& ele : arr) {
        cin >> ele;
    }

    cout << find_array_max(arr, n) << '\n';

    return 0;
}