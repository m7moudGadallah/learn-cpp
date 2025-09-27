#include <iostream>

using namespace std;

long long sum_array(const int arr[], int size) {
    if (size < 1) {
        return 0;
    }

    return arr[size - 1] + sum_array(arr, size - 1);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (auto& ele : arr) {
        cin >> ele;
    }

    cout << sum_array(arr, n) << '\n';

    return 0;
}