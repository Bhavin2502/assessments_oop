#include <iostream>
#include <ctime>
#include <cstdlib> // for system("pause") and system("cls")
#include <string>

using namespace std;

class BankAccount {
public:
    string holderName;
    string branch;
    long long accountNumber;
    double balance;

    BankAccount(const string& name, const string& branch, long long accNumber, double initialBalance)
        : holderName(name), branch(branch), accountNumber(accNumber), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Rs. " << amount << " deposited successfully.\n";
        } else {
            cout << "Invalid amount for deposit.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Rs. " << amount << " withdrawn successfully.\n";
        } else {
            cout << "Invalid amount for withdrawal or insufficient balance.\n";
        }
    }

    void displayBalance() {
        cout << "Your current available balance is Rs. " << balance << endl;
    }
};

class ATM {
public:
    ATM() {
        time_t now = time(0);
        char* dt = ctime(&now);
        cout << "WELCOME TO ATM\nCurrent date: " << dt << endl;
        cout << "Press 1 and Then Press Enter to Access Your Account Via Pin Number\n"
             << "or\nPress 2 and Then Press Enter to get Help.\n";
    }

    void accessAccount(BankAccount& account) {
        int pin = 12345;
        int inputPin;
        cout << "ATM ACCOUNT ACCESS\nEnter Your Acc Pin Access Number! [Only one attempt is allowed] ";
        cin >> inputPin;
        if (inputPin == pin) {
            cout << "Access Granted.\n";

            // Display account information and perform transactions
            int choice;
            double amount;

            do {
                cout << account.holderName << "'s Account\n";
                cout << "Branch: " << account.branch << endl;
                cout << "Account Number: " << account.accountNumber << endl;
                cout << "Present available balance: Rs. " << account.balance << endl;
                cout << "1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        cout << "Enter the amount to be deposited: Rs. ";
                        cin >> amount;
                        account.deposit(amount);
                        break;
                    case 2:
                        cout << "Enter the amount to be withdrawn: Rs. ";
                        cin >> amount;
                        account.withdraw(amount);
                        break;
                    case 3:
                        account.displayBalance();
                        break;
                    case 4:
                        cout << "Thank you for using our ATM!" << endl;
                        break;
                    default:
                        cout << "Invalid choice! Please try again." << endl;
                }

                cout << endl;
                system("pause");
                system("cls");

            } while (choice != 4);

        } else {
            cout << "Incorrect Pin. Access Denied.\n";
        }
    }
};

int main() {
    ATM atm;
    BankAccount userAccount("Rakesh Karva", "Main Street", 123456789, 1000.0);

    int choice;
    cin >> choice;

    if (choice == 1) {
        atm.accessAccount(userAccount);
    } else {
        cout << "Help Menu\n";
        // Add help information here
    }

    return 0;
}

