#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    char name[50];
    float balance;

public:
    void createAccount() {
        cout << "\nEnter Account Number: ";
        cin >> accountNumber;
        cin.ignore();

        cout << "Enter Account Holder Name: ";
        cin.getline(name, 50);

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void displayAccount() {
        cout << "\n----- Account Details -----";
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nAccount Holder : " << name;
        cout << "\nBalance        : " << balance;
        cout << endl;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    void deposit() {
        float amount;
        cout << "\nEnter Amount to Deposit: ";
        cin >> amount;

        balance += amount;

        cout << "Amount Deposited Successfully!";
    }

    void withdraw() {
        float amount;
        cout << "\nEnter Amount to Withdraw: ";
        cin >> amount;

        if (amount > balance) {
            cout << "Insufficient Balance!";
        } else {
            balance -= amount;
            cout << "Withdrawal Successful!";
        }
    }

    void checkBalance() {
        cout << "\nCurrent Balance: " << balance << endl;
    }
};

// Function to write account into file
void writeAccount() {
    BankAccount acc;

    ofstream outFile("bank.dat", ios::binary | ios::app);

    acc.createAccount();

    outFile.write((char*)&acc, sizeof(acc));

    outFile.close();

    cout << "\nAccount Created Successfully!\n";
}

// Function to display all accounts
void displayAllAccounts() {
    BankAccount acc;

    ifstream inFile("bank.dat", ios::binary);

    if (!inFile) {
        cout << "\nFile Not Found!";
        return;
    }

    while (inFile.read((char*)&acc, sizeof(acc))) {
        acc.displayAccount();
    }

    inFile.close();
}

// Function to search account
void searchAccount(int accNo) {
    BankAccount acc;

    bool found = false;

    fstream file("bank.dat", ios::binary | ios::in | ios::out);

    while (file.read((char*)&acc, sizeof(acc))) {

        if (acc.getAccountNumber() == accNo) {

            cout << "\nAccount Found!\n";

            acc.displayAccount();

            int choice;

            cout << "\n1. Deposit";
            cout << "\n2. Withdraw";
            cout << "\n3. Check Balance";
            cout << "\nEnter Choice: ";
            cin >> choice;

            switch (choice) {

            case 1:
                acc.deposit();

                file.seekp(-sizeof(acc), ios::cur);
                file.write((char*)&acc, sizeof(acc));
                break;

            case 2:
                acc.withdraw();

                file.seekp(-sizeof(acc), ios::cur);
                file.write((char*)&acc, sizeof(acc));
                break;

            case 3:
                acc.checkBalance();
                break;

            default:
                cout << "Invalid Choice!";
            }

            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "\nAccount Not Found!\n";
    }
}

int main() {

    int choice, accNo;

    do {

        cout << "\n========== BANK MANAGEMENT SYSTEM ==========";
        cout << "\n1. Create Account";
        cout << "\n2. Display All Accounts";
        cout << "\n3. Search Account";
        cout << "\n4. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            writeAccount();
            break;

        case 2:
            displayAllAccounts();
            break;

        case 3:
            cout << "\nEnter Account Number: ";
            cin >> accNo;

            searchAccount(accNo);
            break;

        case 4:
            cout << "\nThank You for Using Bank Management System!";
            break;

        default:
            cout << "\nInvalid Choice!";
        }

    } while (choice != 4);

    return 0;
}