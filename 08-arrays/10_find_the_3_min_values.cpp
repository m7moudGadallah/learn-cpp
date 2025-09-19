#include <iostream>

using namespace std;

int main() {
    int n, num;

    cin >> n;

    int mn1 = INT_MAX,
        mn2 = INT_MAX,
        mn3 = INT_MAX;

    while (n--) {
        cin >> num;

        if (num < mn1) {
            mn3 = mn2;
            mn2 = mn1;
            mn1 = num;
        }
        else if (num < mn2) {
            mn3 = mn2;
            mn2 = num;
        }
        else if (num < mn3) {
            mn3 = num;
        }
    }

    cout << mn1 << ' ' << mn2 << ' ' << mn3 << '\n';

    return 0;
}