#include <iostream>

using namespace std;

// Menu choice codes
const int MENU_ADD_CODE = 1;
const int MENU_SUBTRACT_CODE = 2;
const int MENU_MULTIPLY_CODE = 3;
const int MENU_DIVIDE_CODE = 4;
const int MENU_END_CODE = 5;

const char DIVIDER_SYMBOL = '*';

inline int menu() {
    cout << "Please Enter your choice (from 1 to 5):\n";
    cout << "1) Add 2 numbers\n";
    cout << "2) Subtract 2 numbers\n";
    cout << "3) Multiply 2 numbers\n";
    cout << "4) Divide 2 numbers\n";
    cout << "5) End the program\n";

    int choice;
    cin >> choice;

    return choice;
}

inline void display_divider(int length = 25) {
    cout << string(length, DIVIDER_SYMBOL) << '\n';
}

inline void display_result(const double& num1, const double& num2, const char& op_symbol, const double& result) {
    cout << num1 << ' ' << op_symbol << ' ' << num2 << " = " << result << '\n';
}

inline void read_numbers(double& num1, double& num2) {
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;
}

inline void add() {
    double num1, num2;
    read_numbers(num1, num2);

    display_result(num1, num2, '+', num1 + num2);
}

inline void subtract() {
    double num1, num2;
    read_numbers(num1, num2);

    display_result(num1, num2, '-', num1 - num2);
}

inline void multiply() {
    double num1, num2;
    read_numbers(num1, num2);

    display_result(num1, num2, '*', num1 * num2);
}

inline void divide() {
    double num1, num2;
    read_numbers(num1, num2);

    if (num2 == 0) {
        cout << "Can't divide by zero!\n";
        return;
    }

    display_result(num1, num2, '/', num1 / num2);
}

inline void bootstrap_calculator() {
    int choice = menu();

    while (choice != MENU_END_CODE) {
        switch (choice) {
            case MENU_ADD_CODE:
                add();
                break;
            case MENU_SUBTRACT_CODE:
                subtract();
                break;
            case MENU_MULTIPLY_CODE:
                multiply();
                break;
            case MENU_DIVIDE_CODE:
                divide();
                break;
            default:
                break;
        }
        display_divider();
        choice = menu();
    }
}

int main() {
    bootstrap_calculator();
    return 0;
}