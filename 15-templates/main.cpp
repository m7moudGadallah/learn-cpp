#include <iostream>
#include <string>
using namespace std;

template<typename Type>
Type my_max(Type a, Type b) {
    return (a > b) ? a : b;
}

struct Person {
    string name;
    int age;

    string to_string() const {
        return name + "::" + std::to_string(age);
    }

    bool operator>(const Person& other) const {
        return age > other.age;
    }
};

int main() {
    Person p{ "John", 20 };
    Person p2{ "Doe", 15 };

    cout << my_max(p, p2).to_string() << '\n';

    return 0;
}
