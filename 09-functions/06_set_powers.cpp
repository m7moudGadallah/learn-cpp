#include <iostream>
#include <cmath>

using namespace std;

inline void set_powers(int arr[], const int& len, int& base) {
    for (int i = 0; i < len; ++i) {
        arr[i] = pow(base, i);
    }
}

inline void print_array(int arr[], const int& len) {
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int len, m;

    cin >> len >> m;

    int arr[len];

    set_powers(arr, len, m);

    print_array(arr, len);

    return 0;
}