#include <iostream>

using namespace std;

void set_left_max(int arr[], int size) {
    if (size < 2) return;

    set_left_max(arr, size - 1);

    arr[size - 1] = max(arr[size - 1], arr[size - 2]);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (auto& ele : arr) {
        cin >> ele;
    }

    set_left_max(arr, n);

    for (auto& ele : arr) {
        cout << ele << ' ';
    }
    cout << '\n';

    return 0;
}