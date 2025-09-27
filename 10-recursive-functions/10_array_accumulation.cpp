#include <iostream>

using namespace std;

void accumulate_array(int arr[], int size) {
    if (size < 2) return;

    accumulate_array(arr, size - 1);

    arr[size - 1] += arr[size - 2];
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (auto& ele : arr) {
        cin >> ele;
    }

    accumulate_array(arr, n);

    for (auto& ele : arr) {
        cout << ele << ' ';
    }
    cout << '\n';

    return 0;
}