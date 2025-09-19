#include <iostream>

using namespace std;

int main() {
    int n, num;
    cin >> n;

    int evens = (n / 2);
    int odds = (evens + (n % 2));
    int odd_sum = 0;
    int even_sum = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> num;

        if (i % 2) odd_sum += num;
        else even_sum += num;
    }

    cout << odd_sum / odds << '\n';
    cout << even_sum / evens << '\n';

    return 0;
}