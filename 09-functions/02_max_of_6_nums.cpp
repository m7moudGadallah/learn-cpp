#include <iostream>

using namespace std;

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int max(int a, int b, int c, int d) {
    return max(max(a, b, c), d);
}

int max(int a, int b, int c, int d, int e) {
    return max(max(a, b, c, d), e);
}

int max(int a, int b, int c, int d, int e, int f) {
    return max(max(a, b, c, d, e), f);
}

int main() {
    cout << max(2, 1, 3, 4, 6, 5) << '\n';
    return 0;
}