#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_BOOKS = 100;
const int MAX_USERS = 10;
const int MAX_BORROWED = 10;

struct user {
    int id {0};
    string name;
    int borrowed_books[MAX_BORROWED];
    int borrowed_quantity {0};
    void print() {
        cout << "id = " << id
             << " name = " << name
             << " borrowed books ids: ";
        
        if (borrowed_quantity == 0) {
            cout << "none\n";
            return;
        }

        sort(borrowed_books, borrowed_books + borrowed_quantity);
        for (int i = 0; i < borrowed_quantity; i++) {
            cout << borrowed_books[i] << ' ';
        }

        cout << endl;
    }
};

struct book {
    int id {0};
    string name;
    int quantity {0};
    int borrowed {0};

    void print() {
        cout << "id = " << id
             << " name = " << name
             << " total quantity " << quantity
             << " total borrowed " << borrowed
             << endl;
    }
};

    bool cmp_book_by_id(book b1, book b2) {
        return b1.id < b2.id;
    }
    bool cmp_book_by_name(book b1, book b2) {
        return b1.name < b2.name;
    }
    bool cmp_user_by_id(user u1, user u2) {
        return u1.id < u2.id;
    }
struct library_system {
    user users[MAX_USERS];
    book books[MAX_BOOKS];

    int books_quantity {0};
    int users_quantity {0};

    void print_menu() {
        cout << "\nTasks\n"
             << "1) add book\n"
             << "2) search books by prefix\n"
             << "3) print who borrowed book by name\n"
             << "4) print library by id\n"
             << "5) print library by name\n"
             << "6) add user\n"
             << "7) user borrow book\n"
             << "8) user return book\n"
             << "9) print users\n"
             << "10) exit";
    }

    void add_book() {
        cout << "Enter book info: id &name & total quantity: ";
        cin >> books[books_quantity].id
            >> books[books_quantity].name
            >> books[books_quantity].quantity;
        books_quantity++;
    }
    void search_books_by_prefix() {
        bool success = 0;
        bool is_prefix = 1;
        string prefix;
        cout << "Enter book name prefix: ";
        cin >> prefix;

        for (int i = 0; i < books_quantity; i++) {
            if (prefix.size() > books[i].name.size()) {
                is_prefix = 0;
            } else {
                for (int j = 0; j < prefix.size(); j++) {
                    if (books[i].name[j] != prefix[j]) {
                        is_prefix = 0;
                        break;
                    }
                }
            }
            if (is_prefix) {
                cout << books[i].name << "\n";
                success = 1;
            }
            else
                is_prefix = 1;
        }
        if (!success)
            cout << "No books with such prefix!\n";
    }
    void print_who_borrowed_book_by_name() {
        string book_name;
        int book_index = -1, book_id;
        cout << "Enter book name: ";
        cin >> book_name;

        for (int i = 0; i < books_quantity; i++) {
            if (books[i].name == book_name) {
                book_index = i;
                break;
            }
        }

        if (book_index == -1) {
            cout << "Invalid book name!\n";
            return;
        }

        if (books[book_index].borrowed == 0) {
            cout << "No user borrowed this book!\n";
            return;
        }

        book_id = books[book_index].id;

        for (int i = 0; i < users_quantity; i++) {
            for (int j = 0; j < users[i].borrowed_quantity; j++) {
                if (users[i].borrowed_books[j] == book_id) {
                    cout << users[i].name << endl;
                    break;
                }
            }
        }
    }
    void print_library_by_id() {
        sort(books, books + books_quantity, cmp_book_by_id);
        for (int i = 0; i < books_quantity; i++) {
            books[i].print();
        }
    }
    void print_library_by_name() {
        sort(books, books + books_quantity, cmp_book_by_name);
        for (int i = 0; i < books_quantity; i++) {
            books[i].print();
        }
    }
    void add_user() {
        cout << "Enter user name & national id: ";
        cin >> users[users_quantity].name
            >> users[users_quantity].id;
        users_quantity++;
    }
    void user_borrow_book() {
        string user_name, book_name;
        int user_index = -1, book_index = -1;
        cout << "Enter user name & book name: ";
        cin >> user_name >> book_name;

        for (int i = 0; i < users_quantity; i++) {
            if (users[i].name == user_name) {
                user_index = i;
                break;
            }
        }
        for (int i = 0; i < books_quantity; i++) {
            if (books[i].name == book_name) {
                book_index = i;
                break;
            }
        }

        if (user_index == -1) {
            cout << "User not found!\n";
            return;
        }
        if (book_index == -1) {
            cout << "Book not found!\n";
            return;
        }

        users[user_index].borrowed_books[users[user_index].borrowed_quantity] = books[book_index].id;
        users[user_index].borrowed_quantity++;
        books[book_index].borrowed++;
    }
    void user_return_book() {
        string user_name, book_name;
        int user_index = -1, book_index = -1, id_index = -1;
        cout << "Enter user name & book name: ";
        cin >> user_name >> book_name;

        for (int i = 0; i < users_quantity; i++) {
            if (users[i].name == user_name) {
                user_index = i;
                break;
            }
        }
        for (int i = 0; i < books_quantity; i++) {
            if (books[i].name == book_name) {
                book_index = i;
                break;
            }
        }

        if (user_index == -1) {
            cout << "User not found!\n";
            return;
        }
        if (book_index == -1) {
            cout << "Book not found!\n";
            return;
        }


        for (int i = 0; i < users[user_index].borrowed_quantity; i++) {
            if (users[user_index].borrowed_books[i] == books[book_index].id) {
                id_index = i;
                break;
            }
        }

        if (id_index == -1) {
            cout << "User don't have the book!\n";
            return;
        }

        if (users[user_index].borrowed_quantity == 1) {
            users[user_index].borrowed_quantity--;
            books[book_index].borrowed--;
            return;
        }
        for (int i = id_index + 1; i < users[user_index].borrowed_quantity; i++) {
            users[user_index].borrowed_books[i - 1] = users[user_index].borrowed_books[i];
        }
        users[user_index].borrowed_quantity--;
        books[book_index].borrowed--;
    }
    void print_users() {
        sort(users, users + users_quantity, cmp_user_by_id);
        for (int i = 0; i < users_quantity; i++) {
            users[i].print();
        }
    }

    void start() {
        int choice;

        cout << "Library System\n";

        print_menu();
        while (1) {

            cout << "Enter your choice [1 - 10]: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                add_book();
                break;
            
            case 2:
                search_books_by_prefix();
                break;
            
            case 3:
                print_who_borrowed_book_by_name();
                break;
            
            case 4:
                print_library_by_id();
                break;
            
            case 5:
                print_library_by_name();
                break;
            
            case 6:
                add_user();
                break;
            
            case 7:
                user_borrow_book();
                break;
            
            case 8:
                user_return_book();
                break;
            
            case 9:
                print_users();
                break;
            
            case 10:
                return;
            
            default:
                cout << "Wrong choice!\n";
                break;
            }
        }
    }
};

int main() {
    library_system().start();
}