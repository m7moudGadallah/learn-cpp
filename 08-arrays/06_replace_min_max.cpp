#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n]{ 0 };
    int mn = INT_MAX, mx = INT_MIN;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        mn = min(mn, arr[i]);
        mx = max(mx, arr[i]);
    }

    for (int i = 0; i < n; ++i) {
        if (arr[i] == mx) arr[i] = mn;
        else if (arr[i] == mn) arr[i] = mx;
    }

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}