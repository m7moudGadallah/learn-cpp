#include <iostream>

using namespace std;

const int NUM_OF_SPECIALIZATIONS = 20;
const int SPECIALIZATION_CAPACITY = 5;
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

struct HospitalQueueEntry {
public:
    string name;
    int status;

    string to_string() const {
        return name + " " + PATIENT_STATUS[status];
    }
};

struct HospitalQueue {
private:
    static const int QUEUE_CAPACITY = SPECIALIZATION_CAPACITY;
    int len;
    HospitalQueueEntry data[QUEUE_CAPACITY];
    int head = 0, tail = 0;

private:
    int increment_pointer(int p) const {
        return (p + QUEUE_CAPACITY + 1) % QUEUE_CAPACITY;
    }

    int decrement_pointer(int p) const {
        return (p + QUEUE_CAPACITY - 1) % QUEUE_CAPACITY;
    }
public:
    HospitalQueue() {
        this->len = 0;
    }

    void add_end(HospitalQueueEntry value) {
        if (is_full()) return;

        tail = increment_pointer(tail);
        if (is_empty()) head = tail;
        ++len;
        data[tail] = value;
    }

    void add_front(HospitalQueueEntry value) {
        if (is_full()) return;

        head = decrement_pointer(head);
        if (is_empty()) head = tail;
        ++len;
        data[head] = value;
    }

    HospitalQueueEntry remove_front() {
        if (is_empty()) {
            return {};
        }

        auto removed_val = data[head];

        head = increment_pointer(head);
        --len;

        return removed_val;
    }

    int size() const {
        return len;
    }

    bool is_empty() const {
        return !size();
    }

    bool is_full() const {
        return len >= QUEUE_CAPACITY;
    }

    void print() const {
        if (is_empty()) return;

        for (int i = 0, current = head; i < len; i++, current = increment_pointer(current)) {
            cout << data[current].to_string() << '\n';
        }
    }
};

HospitalQueue hospital_queues[NUM_OF_SPECIALIZATIONS];

bool add_patient() {
    int specialization;
    string name;
    int status;

    cout << "Enter specialization, name, status: ";
    cin >> specialization >> name >> status;

    auto& spec_queue = hospital_queues[specialization];

    if (spec_queue.is_full()) {
        return false;
    }

    const HospitalQueueEntry entry{ name, status };

    // Regular Patient
    if (PATIENT_STATUS[status] == PATIENT_STATUS[0]) {
        spec_queue.add_end(entry);
        return true;
    }

    // Urgent patient
    spec_queue.add_front(entry);
    return true;
}

void print_patients() {
    for (int i = 0; i < NUM_OF_SPECIALIZATIONS; ++i) {
        const auto& spec_queue = hospital_queues[i];
        if (spec_queue.is_empty()) continue;

        cout << "There are " << spec_queue.size() << " patients in specialization " << i << "\n";

        spec_queue.print();

        cout << "\n";
    }
}

void get_next_patient() {
    cout << "Enter specialization: ";
    int specialization;
    cin >> specialization;

    auto& spec_queue = hospital_queues[specialization];

    if (spec_queue.is_empty()) {
        cout << "No patients at the moment. Have rest, Dr!\n";
        return;
    }

    const auto& entry = spec_queue.remove_front();
    cout << entry.name << " please go with the Dr\n";
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

