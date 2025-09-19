#include <iostream>

using namespace std;

int main() {
    int n, q, num, found;
    cin >> n;

    int arr[n]{ 0 };

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cin >> q;

    while (q--) {
        cin >> num;
        found = -1;

        for (int i = n - 1; i >= 0; --i) {
            if (arr[i] == num) {
                found = i;
                break;
            }
        }

        cout << found << '\n';
    }

    return 0;
}