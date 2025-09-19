#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    int arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int left = 0, right = n - 1;

    while (left < right) {
        swap(arr[left++], arr[right--]);
    }

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}