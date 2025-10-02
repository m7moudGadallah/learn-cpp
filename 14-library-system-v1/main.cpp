#include <iostream>

using namespace std;

// Consts
const int MAX_NUM_OF_USERS_IN_LIBRARY = 100;
const int MAX_NUM_OF_BOOKS_IN_LIBRARY = 100;
const int MAX_NUM_OF_BORROWED_BOOKS_BY_USER = 10;
const int SEARCH_NOT_FOUND_CODE = -1;

// Structures
struct User {
private:
    static int sequence_id;
    const static int BORROWING_BOOKS_CAPCITY = MAX_NUM_OF_BORROWED_BOOKS_BY_USER;

public:
    int id;
    string name;
    int borrowed_books_ids[User::BORROWING_BOOKS_CAPCITY];
    int borrowed_books_count;

public:
    User() {
        id = ++sequence_id;
        name = "";
        borrowed_books_count = 0;
    }

    bool can_borrow() {
        return borrowed_books_count < User::BORROWING_BOOKS_CAPCITY;
    }


    bool borrow_book(int book_id) {
        if (!can_borrow())  return false;
        borrowed_books_ids[borrowed_books_count++] = book_id;
        return true;
    }

    int find_borrowed_book(int book_id) {
        for (int i = 0; i < borrowed_books_count; ++i) {
            if (borrowed_books_ids[i] == book_id)
                return i;
        }
        return SEARCH_NOT_FOUND_CODE;
    }

    bool has_borrowed(int book_id) {
        return find_borrowed_book(book_id) >= 0;
    }

    bool return_book(int book_id) {
        int found = find_borrowed_book(book_id);

        if (found == SEARCH_NOT_FOUND_CODE) return false;

        swap(borrowed_books_ids[found], borrowed_books_ids[borrowed_books_count - 1]);
        --borrowed_books_count;
        return true;
    }

    string to_string() const {
        return ("User: { id= " + std::to_string(id) + ", name= " + name + " }");
    }
};

struct Book {
private:
    static int sequence_id;
public:
    int id;
    string name;
    int quantity;
    int total_borrowed;

    Book() {
        id = ++sequence_id;
        name = "";
        quantity = 0;
        total_borrowed = 0;
    }

    bool is_name_prefix(string prefix_name) const {
        if (prefix_name.size() > name.size()) return false;

        for (int i = 0; i < prefix_name.size(); ++i) {
            if (prefix_name[i] != name[i]) return false;
        }

        return true;
    }


    bool can_be_borrowed() {
        return quantity > 0;
    }

    bool borrow_by_user() {
        if (quantity <= 0) return false;

        --quantity;
        ++total_borrowed;
        return true;
    }

    bool return_by_user() {
        if (total_borrowed <= 0) return false;

        --total_borrowed;
        ++quantity;

        return true;
    }

    bool is_borrowed() {
        return total_borrowed > 0;
    }

    string to_string() const {
        return ("Book: { id= " + std::to_string(id) + ", name= " + name + ", quantity= " + std::to_string(quantity) + ", total_borrowed= " + std::to_string(total_borrowed) + " }");
    }
};

struct MenuOptions {
    static const int ADD_BOOK = 1;
    static const int SEARCH_BOOKS_BY_PREFIX = 2;
    static const int PRINT_WHO_BORROWED_BOOK_NAME = 3;
    static const int PRINT_LIBRARY_BY_ID = 4;
    static const int PRINT_LIBRARY_BY_NAME = 5;
    static const int ADD_USER = 6;
    static const int USER_BORROW_BOOK = 7;
    static const int USER_RETURN_BOOK = 8;
    static const int PRINT_USERS = 9;
    static const int EXIT = 10;
};

struct UserController {
private:
    static const int CAPCITY = MAX_NUM_OF_USERS_IN_LIBRARY;
    User users[UserController::CAPCITY];
    int length = 0;

private:
    bool is_list_empty() const {
        return length <= 0;
    }

    bool is_list_full() const {
        return length >= UserController::CAPCITY;
    }
public:
    void add_user() {
        if (is_list_full()) {
            cout << "Sorry, user list is fully so we can't accept new users!";
            return;
        }

        cout << "Enter user info: name: ";
        User user{};
        cin >> user.name;
        users[length++] = user;
    }

    void display_users() const {
        if (is_list_empty()) {
            cout << "No available users to display!\n";
            return;
        }

        for (int i = 0; i < length; ++i) {
            cout << users[i].to_string() << '\n';
        }
    }

    void display_who_borrowed(Book book) {
        for (int i = 0; i < length; ++i) {
            if (users[i].has_borrowed(book.id)) {
                cout << users[i].to_string() << '\n';
            }
        }
    }

    int find_user_by_name(string name) const {
        for (int i = 0; i < length; ++i) {
            if (users[i].name == name) return i;
        }
        return SEARCH_NOT_FOUND_CODE;
    }

    User get_user(int idx) const {
        return users[idx];
    }

    void update_user(int idx, User updated_user) {
        users[idx] = updated_user;
    }
};

struct BookController {
private:
    static const int CAPCITY = MAX_NUM_OF_BOOKS_IN_LIBRARY;
    Book books[BookController::CAPCITY];
    int length = 0;

private:
    bool is_list_empty() const {
        return length <= 0;
    }

    bool is_list_full() const {
        return length >= BookController::CAPCITY;
    }

public:
    void add_book() {
        if (is_list_full()) {
            cout << "Sorry, book list is fully so we can't accept new books!";
            return;
        }

        cout << "Enter book info: name & total quantity: ";
        Book book{};
        cin >> book.name >> book.quantity;
        books[length++] = book;
    }

    void search_books_by_prefix() const {
        string prefix_name;
        cout << "Enter book prefix name: ";
        cin >> prefix_name;

        bool found = false;

        for (int i = 0; i < length; ++i) {
            if (books[i].is_name_prefix(prefix_name)) {
                found = true;
                cout << books[i].to_string() << '\n';
            }
        }

        if (!found) {
            cout << "There's no books with this prefix name!\n";
        }
    }

    void display_by_sorted_names() const {
        if (is_list_empty()) {
            cout << "No books available to display!\n";
            return;
        }

        int sorted_idxs[length];
        for (int i = 0;i < length; ++i) {
            sorted_idxs[i] = i;
        }

        // selection sort by name
        for (int i = 0; i < length; ++i) {
            int mn_idx = i;

            for (int j = i + 1; j < length; ++j) {
                if (books[sorted_idxs[j]].name < books[sorted_idxs[mn_idx]].name) {
                    mn_idx = j;
                }
            }

            swap(sorted_idxs[i], sorted_idxs[mn_idx]);
        }

        for (const auto& idx : sorted_idxs) {
            cout << books[idx].to_string() << '\n';
        }
    }

    void display_by_sorted_ids() const {
        if (is_list_empty()) {
            cout << "No books available to display!\n";
            return;
        }

        for (int i = 0; i < length; ++i) {
            cout << books[i].to_string() << '\n';
        }
    }

    int find_book_by_name(string name) const {
        for (int i = 0; i < length; ++i) {
            if (books[i].name == name) return i;
        }
        return SEARCH_NOT_FOUND_CODE;
    }

    Book get_book(int idx) const {
        return books[idx];
    }

    void update_book(int idx, Book updated_book) {
        books[idx] = updated_book;
    }
};

struct LibrarySystem {
private:
    UserController user_controller;
    BookController book_controller;

private:
    int menu() {
        cout << "Library Menu:\n"
            << "1) add_book\n"
            << "2) search_books_by_prefix\n"
            << "3) print_who_borrowed_book_by_name\n"
            << "4) print_library_by_id\n"
            << "5) print_library_by_name\n"
            << "6) add_user\n"
            << "7) user_borrow_book\n"
            << "8) user_return_book\n"
            << "9) print_users\n"
            << "10) exit\n"
            << "\nEnter you menu choice [1 - 10]: ";
        int choice; cin >> choice;
        return choice;
    }

    bool get_user_and_book(int& user_idx, int& book_idx, User& user, Book& book) {
        string book_name, user_name;

        cout << "Enter user name and book name: ";
        cin >> user_name >> book_name;

        user_idx = user_controller.find_user_by_name(user_name);
        if (user_idx == SEARCH_NOT_FOUND_CODE) {
            cout << "Invalid user name!\n";
            return false;
        }

        book_idx = book_controller.find_book_by_name(book_name);
        if (book_idx == SEARCH_NOT_FOUND_CODE) {
            cout << "Invalid book name!\n";
            return false;
        }

        user = user_controller.get_user(user_idx);
        book = book_controller.get_book(book_idx);

        return true;
    }

    void borrow_book() {
        int user_idx{};
        int book_idx{};
        User user{};
        Book book{};

        if (!get_user_and_book(user_idx, book_idx, user, book)) {
            return;
        }

        if (!book.can_be_borrowed()) {
            cout << "Sorry, This book can't be borrowed now!\n";
            return;
        }

        if (!user.can_borrow()) {
            cout << "Sorry, This user can't borrow books!\n";
            return;
        }

        user.borrow_book(book.id);
        book.borrow_by_user();

        user_controller.update_user(user_idx, user);
        book_controller.update_book(book_idx, book);
    }

    void return_book() {
        int user_idx{};
        int book_idx{};
        User user{};
        Book book{};

        if (!get_user_and_book(user_idx, book_idx, user, book)) {
            return;
        }

        if (!user.return_book(book.id)) {
            cout << "User wasn't borrow this book\n";
            return;
        }

        book.return_by_user();

        user_controller.update_user(user_idx, user);
        book_controller.update_book(book_idx, book);
    }

    void display_users_who_borrowed_book_by_name() {
        string book_name;
        cout << "Enter Book Name: ";
        cin >> book_name;

        int book_idx = book_controller.find_book_by_name(book_name);
        if (book_idx == SEARCH_NOT_FOUND_CODE) {
            cout << "Invalid book name!\n";
            return;
        }

        Book book = book_controller.get_book(book_idx);

        if (!book.is_borrowed()) {
            cout << "No users have borrowed this book yet!\n";
            return;
        }

        user_controller.display_who_borrowed(book);
    }

public:
    void bootstrap() {
        int choice;
        while ((choice = menu()) != MenuOptions::EXIT) {
            switch (choice) {
                case MenuOptions::ADD_BOOK:
                    book_controller.add_book();
                    break;
                case MenuOptions::SEARCH_BOOKS_BY_PREFIX:
                    book_controller.search_books_by_prefix();
                    break;
                case MenuOptions::PRINT_WHO_BORROWED_BOOK_NAME:
                    display_users_who_borrowed_book_by_name();
                    break;
                case MenuOptions::PRINT_LIBRARY_BY_ID:
                    book_controller.display_by_sorted_ids();
                    break;
                case MenuOptions::PRINT_LIBRARY_BY_NAME:
                    book_controller.display_by_sorted_names();
                    break;
                case MenuOptions::ADD_USER:
                    user_controller.add_user();
                    break;
                case MenuOptions::USER_BORROW_BOOK:
                    borrow_book();
                    break;
                case MenuOptions::USER_RETURN_BOOK:
                    return_book();
                    break;
                case MenuOptions::PRINT_USERS:
                    user_controller.display_users();
                    break;
                default:
                    break;
            }

            cout << string(25, '*') << "\n\n";
        }
    }
};

// Static variable definitions
int User::sequence_id = 0;
int Book::sequence_id = 0;

int main() {
    LibrarySystem system;
    system.bootstrap();
    return 0;
}