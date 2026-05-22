#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Book Class
class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        isIssued = false;
    }
};

// Member Class
class Member {
public:
    int memberId;
    string name;

    Member(int id, string n) {
        memberId = id;
        name = n;
    }
};

// Library Class
class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:

    // Add Book
    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
        cout << "Book added successfully!\n";
    }

    // Add Member
    void addMember(int id, string name) {
        members.push_back(Member(id, name));
        cout << "Member added successfully!\n";
    }

    // Issue Book
    void issueBook(int bookId) {
        for (auto &book : books) {
            if (book.id == bookId && !book.isIssued) {
                book.isIssued = true;
                cout << "Book issued successfully!\n";
                return;
            }
        }

        cout << "Book not available.\n";
    }

    // Return Book
    void returnBook(int bookId) {
        for (auto &book : books) {
            if (book.id == bookId && book.isIssued) {
                book.isIssued = false;
                cout << "Book returned successfully!\n";
                return;
            }
        }

        cout << "Invalid return.\n";
    }

    // Search by Title
    void searchByTitle(string title) {
        for (auto &book : books) {
            if (book.title == title) {
                cout << "Found: " << book.title
                     << " by " << book.author << endl;
                return;
            }
        }

        cout << "Book not found.\n";
    }

    // Search by Author
    void searchByAuthor(string author) {
        for (auto &book : books) {
            if (book.author == author) {
                cout << "Found: " << book.title << endl;
            }
        }
    }

    // Display Books
    void displayBooks() {
        for (auto &book : books) {
            cout << book.id << " | "
                 << book.title << " | "
                 << book.author << " | "
                 << (book.isIssued ? "Issued" : "Available")
                 << endl;
        }
    }
};

// Main Function
int main() {

    Library lib;
    int choice;

    do {
        cout << "\n===== LIBRARY MENU =====\n";
        cout << "1. Add Book\n";
        cout << "2. Add Member\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Search by Title\n";
        cout << "6. Search by Author\n";
        cout << "7. Display Books\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        int id;
        string title, author, name;

        switch (choice) {

        case 1:
            cout << "Enter Book ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Title: ";
            getline(cin, title);

            cout << "Enter Author: ";
            getline(cin, author);

            lib.addBook(id, title, author);
            break;

        case 2:
            cout << "Enter Member ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Name: ";
            getline(cin, name);

            lib.addMember(id, name);
            break;

        case 3:
            cout << "Enter Book ID to issue: ";
            cin >> id;

            lib.issueBook(id);
            break;

        case 4:
            cout << "Enter Book ID to return: ";
            cin >> id;

            lib.returnBook(id);
            break;

        case 5:
            cin.ignore();

            cout << "Enter Title: ";
            getline(cin, title);

            lib.searchByTitle(title);
            break;

        case 6:
            cin.ignore();

            cout << "Enter Author: ";
            getline(cin, author);

            lib.searchByAuthor(author);
            break;

        case 7:
            lib.displayBooks();
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
