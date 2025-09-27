#include <iostream>

using namespace std;

bool is_palindrome(const int arr[], int left, int right) {
    if (left > right) return true;

    if (arr[left] != arr[right]) return false;

    return is_palindrome(arr, left + 1, right - 1);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (auto& ele : arr) {
        cin >> ele;
    }

    cout << is_palindrome(arr, 0, n - 1) << '\n';

    return 0;
}