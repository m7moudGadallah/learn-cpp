#include <iostream>
#include <vector>

using namespace std;

int sum_vector(const vector<int>& v) {
    int sum = 0;

    for (const auto& val : v) {
        sum += val;
    }

    return sum;
}

int max_3stack_sum(vector<int>& a, vector<int>& b, vector<int>& c) {
    int a_sum = sum_vector(a), b_sum = sum_vector(b), c_sum = sum_vector(c);
    
    while ((a_sum and b_sum and c_sum) and !(a_sum == b_sum and b_sum == c_sum)) {
        int mx_sum = max(a_sum, max(b_sum, c_sum));

        if (a_sum == mx_sum) {
            a_sum -= a.back();
            a.pop_back();
        }
        else if (b_sum == mx_sum) {
            b_sum -= b.back();
            b.pop_back();
        }
        else {
            c_sum -= c.back();
            c.pop_back();
        }
    }

    return min(a_sum, min(b_sum, c_sum));
}

int main() {
    vector<int> a{ 1, 2, 3, 4 };
    vector<int> b{ 2, 2, 2, 4, 0 };
    vector<int> c{ 0, 3, 3, 5 };

    cout << max_3stack_sum(a, b, c) << '\n';

    return 0;
}