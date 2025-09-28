#include <iostream>

using namespace std;

const int NUM_OF_SPECIALIZATIONS = 20;
const int NUM_OF_QUEUES_PER_SPECIALIZATION = 5;
const int MAX_PATIENT_PER_SPECIALIZATION = 5;
const int MENU_CODE__ADD_PATIENT = 1;
const int MENU_CODE__PRINT_ALL_PATIENTS = 2;
const int MENU_CODE__GET_NEXT_PATIENT = 3;
const int MENU_CODE__EXIT = 4;
const string PATIENT_STATUS[]{ "regular", "urgent" };

const string specialization[NUM_OF_SPECIALIZATIONS] = {
    "Pediatrics",
    "Surgery",
    "Cardiology",
    "Neurology",
    "Oncology",
    "Orthopedics",
    "Gynecology",
    "Dermatology",
    "Psychiatry",
    "Radiology",
    "Anesthesiology",
    "Emergency Medicine",
    "Internal Medicine",
    "Ophthalmology",
    "ENT (Ear, Nose, Throat)",
    "Urology",
    "Gastroenterology",
    "Endocrinology",
    "Pulmonology",
    "Nephrology"
};

string specialization_patient_queue[NUM_OF_SPECIALIZATIONS][MAX_PATIENT_PER_SPECIALIZATION];
int specialization_queue_len[NUM_OF_SPECIALIZATIONS];

void shift_queue_left(string queue[], int size) {
    if (size < 2) return;
    for (int i = 0; i < size - 1; i++) {
        queue[i] = queue[i + 1];
    }
}

void shift_queue_right(string queue[], int size) {
    if (size < 2) return;
    for (int i = size - 1; i > 0; i--) {
        queue[i] = queue[i - 1];
    }
}


string serialize_patient(string name, int status) {
    return to_string(status) + "#" + name;
}

void deserialize_patient(string serial, string& name, int& status) {
    status = (serial[0] - '0');
    name = serial.substr(2, serial.size() - 2);
}

bool add_patient() {
    int specialization;
    string name;
    int status;

    cout << "Enter specialization, name, status: ";
    cin >> specialization >> name >> status;

    int& curr_queue_len = specialization_queue_len[specialization];

    if (curr_queue_len >= MAX_PATIENT_PER_SPECIALIZATION) {
        return false;
    }

    const string patient = serialize_patient(name, status);

    // Regular Patient
    if (PATIENT_STATUS[status] == PATIENT_STATUS[0]) {
        specialization_patient_queue[specialization][curr_queue_len] = patient;
        ++curr_queue_len;
        return true;
    }

    // Urgent patient
    shift_queue_right(specialization_patient_queue[specialization], MAX_PATIENT_PER_SPECIALIZATION);
    specialization_patient_queue[specialization][0] = patient;
    ++curr_queue_len;
    return true;
}

void print_patients() {
    for (int i = 0; i < NUM_OF_SPECIALIZATIONS; ++i) {
        const int& queue_len = specialization_queue_len[i];
        if (queue_len <= 0) continue;

        cout << "There are " << queue_len << " patients in specialization " << i << "\n";

        for (int j = 0; j < queue_len; ++j) {
            string name;
            int status;
            deserialize_patient(specialization_patient_queue[i][j], name, status);
            cout << name << ' ' << PATIENT_STATUS[status] << '\n';
        }

        cout << "\n";
    }
}

void get_next_patient() {
    cout << "Enter specialization: ";
    int specialization;
    cin >> specialization;

    int& queue_len = specialization_queue_len[specialization];

    if (queue_len == 0) {
        cout << "No patients at the moment. Have rest, Dr!\n";
        return;
    }

    string name;
    int status;
    deserialize_patient(specialization_patient_queue[specialization][0], name, status);
    cout << name << " please go with the Dr\n";
    shift_queue_left(specialization_patient_queue[specialization], MAX_PATIENT_PER_SPECIALIZATION);
    --queue_len;
}

int menu() {
    cout << "Enter your choice\n"
        << "1) Add new patient\n"
        << "2) Print all patients\n"
        << "3) Get next patient\n"
        << "4) Exit\n";

    int choice;
    cin >> choice;
    cout << "*******************************************\n";

    return choice;
}

void system_bootstrap() {
    int choice;

    while ((choice = menu()) != MENU_CODE__EXIT) {
        switch (choice) {
            case MENU_CODE__ADD_PATIENT: {
                if (!add_patient()) {
                    cout << "Sorry we can't add more patients for this specialization!\n";
                }
                break;
            }
            case MENU_CODE__PRINT_ALL_PATIENTS:
                print_patients();
                break;
            case MENU_CODE__GET_NEXT_PATIENT:
                get_next_patient();
                break;
            default:
                break;
        }
    }
}

int main() {
    system_bootstrap();
    return 0;
}

