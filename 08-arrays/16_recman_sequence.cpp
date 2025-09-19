#include <iostream>

using namespace std;

int main() {
    const int MAX_INDEX = 201;
    bool visited[MAX_INDEX * 10]{ 0 };

    int n;
    cin >> n;

    int ans = 0;
    int lastValue = 0,
        lastIndex = 0;

    while (n) {
        int newVal = (lastValue - lastIndex - 1);

        if (newVal <= 0 or visited[newVal]) {
            newVal = (lastValue + lastIndex + 1);
        }

        visited[newVal] = true;
        lastValue = newVal;
        ++lastIndex;
        ans = lastValue;

        --n;
    }

    cout << ans << '\n';

    return 0;
}