#include <iostream>
#include <stack>

using namespace std;

int reverse_num(int num) {
    int ans = 0;

    while (num) {
        ans = ans * 10 + (num % 10);
        num /= 10;
    }

    return ans;
}

int main() {
    int num; cin >> num;
    cout << reverse_num(num) << '\n';
    return 0;
}