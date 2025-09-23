#include <iostream>

using namespace std;

inline void read_array(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

inline bool is_palindrome_array(int arr[], int size) {
    int left = 0, right = size - 1;

    while (left < right) {
        if (arr[left++] != arr[right--]) {
            return false;
        }
    }

    return true;
}

int main() {
    int size;
    cin >> size;

    int arr[size];

    read_array(arr, size);

    cout << boolalpha << is_palindrome_array(arr, size) << '\n';

    return 0;
}