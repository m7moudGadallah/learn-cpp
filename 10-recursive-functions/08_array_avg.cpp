#include <iostream>

using namespace std;

double calc_array_avg(const int arr[], int size) {
    if (size < 1) {
        return 0;
    }

    double prev_avg = calc_array_avg(arr, size - 1);

    return (prev_avg + (arr[size - 1] - prev_avg) / size);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (auto& ele : arr) {
        cin >> ele;
    }

    cout << calc_array_avg(arr, n) << '\n';

    return 0;
}