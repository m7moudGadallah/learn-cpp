#include <iostream>

using namespace std;

int main() {
    // const values
    const int ADD_NEW_EMP_CHOICE = 1;
    const int PRINT_ALL_EMP_CHOICE = 2;
    const int DELETE_BY_AGE_CHOICE = 3;
    const int UPDATE_SALARY_BY_NAME_CHOICE = 4;
    const int MAX_NUM_OF_EMP = 500;
    const char DIVIDER_SYMBOL = '*';

    // Data stores
    int last_index = 0;
    string emp_names[MAX_NUM_OF_EMP];
    int emp_ages[MAX_NUM_OF_EMP];
    double emp_salaries[MAX_NUM_OF_EMP];
    char emp_genders[MAX_NUM_OF_EMP];

    while (true) {
        // Enter user choice
        cout << "\nEnter your choice:\n";
        cout << "1) Add new employee\n";
        cout << "2) Print all employees\n";
        cout << "3) Delete by age\n";
        cout << "4) Update Salary by name\n";

        int choice;
        cin >> choice;
        
        cout << string(25, DIVIDER_SYMBOL) << '\n';

        // Handle user request
        switch (choice) {
            case ADD_NEW_EMP_CHOICE: {
                if (last_index >= MAX_NUM_OF_EMP) {
                    cout << "Sorry, You reach limit (" << MAX_NUM_OF_EMP << " employees)";
                    break;
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
                break;
            }

            case PRINT_ALL_EMP_CHOICE: {
                for (int i = 0; i < last_index; ++i) {
                    cout << emp_names[i] << ' ' << emp_ages[i] << ' ' << emp_salaries[i] << ' ' << emp_genders[i] << '\n';
                }
                break;
            }

            case DELETE_BY_AGE_CHOICE: {
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
                break;
            }

            case UPDATE_SALARY_BY_NAME_CHOICE: {
                string emp_name;
                double new_salary;

                cout << "Enter the name and salary: ";
                cin >> emp_name >> new_salary;

                for (int i = 0; i < last_index; ++i) {
                    if (emp_names[i] == emp_name) {
                        emp_salaries[i] = new_salary;
                        break;
                    }
                }

                cout << "Can't find employee with [name: " << emp_name << "]\n";
                break;
            }

            default: {
                cout << "Unsupported choice\n";
                break;
            }
        }
    }
    return 0;
}