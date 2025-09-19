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
        if (arr[left++] != arr[right--]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}