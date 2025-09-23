#include <iostream>

using namespace std;

// const global values
const int ADD_NEW_EMP_CHOICE = 1;
const int PRINT_ALL_EMP_CHOICE = 2;
const int DELETE_BY_AGE_CHOICE = 3;
const int UPDATE_SALARY_BY_NAME_CHOICE = 4;
const int MAX_NUM_OF_EMP = 500;
const char DIVIDER_SYMBOL = '*';

// Global Data stores
int last_index = 0;
string emp_names[MAX_NUM_OF_EMP];
int emp_ages[MAX_NUM_OF_EMP];
double emp_salaries[MAX_NUM_OF_EMP];
char emp_genders[MAX_NUM_OF_EMP];

// Functions

inline int menu() {
    // Enter user choice
    cout << "\nEnter your choice:\n";
    cout << "1) Add new employee\n";
    cout << "2) Print all employees\n";
    cout << "3) Delete by age\n";
    cout << "4) Update Salary by name\n";

    int choice;
    cin >> choice;

    cout << string(25, DIVIDER_SYMBOL) << '\n';

    return choice;
}

inline void add_new_employee() {
    if (last_index >= MAX_NUM_OF_EMP) {
        cout << "Sorry, You reach limit (" << MAX_NUM_OF_EMP << " employees)";
        return;
    }

    cout << "Enter name: ";
    cin >> emp_names[last_index];

    cout << "Enter age: ";
    cin >> emp_ages[last_index];

    cout << "Enter salary: ";
    cin >> emp_salaries[last_index];

    cout << "Enter gender (M/F): ";
    cin >> emp_genders[last_index];

    ++last_index;
}

void inline print_all_employees() {
    for (int i = 0; i < last_index; ++i) {
        cout << emp_names[i] << ' ' << emp_ages[i] << ' ' << emp_salaries[i] << ' ' << emp_genders[i] << '\n';
    }
}

void inline delete_employee_by_age() {
    int start_age, end_age;

    cout << "Enter start and end age: ";
    cin >> start_age >> end_age;

    for (int i = 0; i < last_index; ++i) {
        const int& emp_age = emp_ages[i];

        if (emp_age >= start_age and emp_age <= end_age) {
            --last_index;
            swap(emp_names[i], emp_names[last_index]);
            swap(emp_ages[i], emp_ages[last_index]);
            swap(emp_salaries[i], emp_salaries[last_index]);
            swap(emp_genders[i], emp_genders[last_index]);
        }
    }
}

void inline update_employee_salary_by_name() {
    string emp_name;
    double new_salary;

    cout << "Enter the name and salary: ";
    cin >> emp_name >> new_salary;

    for (int i = 0; i < last_index; ++i) {
        if (emp_names[i] == emp_name) {
            emp_salaries[i] = new_salary;
            return;
        }
    }

    cout << "Can't find employee with [name: " << emp_name << "]\n";
}

void inline bootstrap_system() {
    while (true) {

        int choice = menu();

        // Handle user request
        switch (choice) {
            case ADD_NEW_EMP_CHOICE:
                add_new_employee();
                break;

            case PRINT_ALL_EMP_CHOICE:
                print_all_employees();
                break;

            case DELETE_BY_AGE_CHOICE:
                delete_employee_by_age();
                break;

            case UPDATE_SALARY_BY_NAME_CHOICE: {
                update_employee_salary_by_name();
                break;
            }

            default: {
                cout << "Unsupported choice\n";
                break;
            }
        }
    }
}

int main() {
    bootstrap_system();
    return 0;
}