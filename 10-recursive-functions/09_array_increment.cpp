#include <iostream>

using namespace std;

void inc_array_by_i(int arr[], int size) {
    if (size < 1) return;

    arr[size - 1] += size - 1;

    inc_array_by_i(arr, size - 1);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (auto& ele : arr) {
        cin >> ele;
    }

    inc_array_by_i(arr, n);

    for (auto& ele : arr) {
        cout << ele << ' ';
    }
    cout << '\n';

    return 0;
}