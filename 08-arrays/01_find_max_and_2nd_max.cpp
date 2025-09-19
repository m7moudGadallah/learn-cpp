#include <iostream>

using namespace std;

int main() {
    int n, num;
    cin >> n;

    int mx = INT_MIN,
        mx2 = INT_MIN;

    while (n--) {
        cin >> num;

        if (num > mx) {
            mx2 = mx;
            mx = num;
        }
        else if (num >= mx2) {
            mx2 = num;
        }
    }

    cout << mx << ' ' << mx2 << '\n';

    return 0;
}