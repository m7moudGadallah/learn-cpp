#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int running_sub_size = 0;
    int last_num = INT_MIN, num;
    long ans = 0;

    while (n--) {
        cin >> num;

        running_sub_size += (num > last_num);

        if (num <= last_num) {
            ans += (running_sub_size * (running_sub_size + 1)) / 2;
            running_sub_size = 1;
        }

        last_num = num;
    }

    ans += (running_sub_size * (running_sub_size + 1)) / 2;

    cout << ans << '\n';

    return 0;
}