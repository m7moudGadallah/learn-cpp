#include <iostream>

const int MAX_NUM_RANGE = 500;

using namespace std;

int main() {
    int n, num;
    bool visited[MAX_NUM_RANGE + 1]{ false };
    cin >> n;

    while (n--) {
        cin >> num;
        if (visited[num]) continue;

        visited[num] = true;
        cout << num << " ";
    }
    cout << '\n';

    return 0;
}