#include <iostream>

using namespace std;

void set_right_max(int arr[], int size) {
    if (size < 2) return;

    arr[size - 2] = max(arr[size - 2], arr[size - 1]);

    set_right_max(arr, size - 1);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (auto& ele : arr) {
        cin >> ele;
    }

    set_right_max(arr, n);

    for (const auto& ele : arr) {
        cout << ele << ' ';
    }
    cout << '\n';

    return 0;
}