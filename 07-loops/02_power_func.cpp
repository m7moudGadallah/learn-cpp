#include <bits/stdc++.h>

using namespace std;

int main() {
    int num, pow;

    cin >> num >> pow;

    long res = 1;

    while (pow >= 1) {
        res *= num;
        --pow;
    }

    cout << res << "\n";

    return 0;
}