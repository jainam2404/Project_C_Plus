#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    double balance; 

protected:
    string accountNumber;
    string accountHolderName;

public:
    BankAccount(string accNum, string holder, double bal) {
        accountNumber = accNum;
        accountHolderName = holder;
        balance = bal;
    }


    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid amount!" << endl;
        }
    }


    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    double getBalance() { 
        return balance;
    }

    virtual void displayAccountInfo() {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nAccount Holder: " << accountHolderName;
        cout << "\nBalance: " << balance << endl;
    }


    virtual void calculateInterest() {
        cout << "No specific interest for base account.\n";
    }
};


class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string accNum, string holder, double bal, double rate)
        : BankAccount(accNum, holder, bal), interestRate(rate) {}

    void calculateInterest() override { 
        double interest = getBalance() * (interestRate / 100);
        cout << "Savings Interest: " << interest << endl;
    }

    void displayAccountInfo() override {
        BankAccount::displayAccountInfo();
        cout << "Interest Rate: " << interestRate << "%\n";
    }
};


class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(string accNum, string holder, double bal, double limit)
        : BankAccount(accNum, holder, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount <= getBalance() + overdraftLimit) {
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Overdraft limit exceeded!\n";
        }
    }

    void displayAccountInfo() override {
        BankAccount::displayAccountInfo();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};


class FixedDepositAccount : public BankAccount {
private:
    int term; 
    double interestRate;

public:
    FixedDepositAccount(string accNum, string holder, double bal, int t, double rate)
        : BankAccount(accNum, holder, bal), term(t), interestRate(rate) {}

    void calculateInterest() override {
        double interest = getBalance() * (interestRate / 100) * (term / 12.0);
        cout << "Fixed Deposit Interest for " << term << " months: " << interest << endl;
    }

    void displayAccountInfo() override {
        BankAccount::displayAccountInfo();
        cout << "Term: " << term << " months\n";
        cout << "Interest Rate: " << interestRate << "%\n";
    }
};


int main() {
    int choice;
    BankAccount* account = nullptr;

    do {
        cout << "\n===== Bank Menu =====\n";
        cout << "1. Create Savings Account\n";
        cout << "2. Create Checking Account\n";
        cout << "3. Create Fixed Deposit Account\n";
        cout << "4. Deposit\n";
        cout << "5. Withdraw\n";
        cout << "6. Display Account Info\n";
        cout << "7. Calculate Interest\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        string accNum, name;
        double bal, rate, limit;
        int term, amount;

        switch (choice) {
        case 1:
            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Balance: ";
            cin >> bal;
            cout << "Enter Interest Rate (%): ";
            cin >> rate;
            account = new SavingsAccount(accNum, name, bal, rate);
            cout << "Savings Account Created!\n";
            break;

        case 2:
            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Balance: ";
            cin >> bal;
            cout << "Enter Overdraft Limit: ";
            cin >> limit;
            account = new CheckingAccount(accNum, name, bal, limit);
            cout << "Checking Account Created!\n";
            break;

        case 3:
            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Balance: ";
            cin >> bal;
            cout << "Enter Term (months): ";
            cin >> term;
            cout << "Enter Interest Rate (%): ";
            cin >> rate;
            account = new FixedDepositAccount(accNum, name, bal, term, rate);
            cout << "Fixed Deposit Account Created!\n";
            break;

        case 4:
            if (account) {
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account->deposit(amount);
            } else
                cout << "No account created yet!\n";
            break;

        case 5:
            if (account) {
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account->withdraw(amount);
            } else
                cout << "No account created yet!\n";
            break;

        case 6:
            if (account)
                account->displayAccountInfo();
            else
                cout << "No account created yet!\n";
            break;

        case 7:
            if (account)
                account->calculateInterest(); 
            else
                cout << "No account created yet!\n";
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    delete account;
    return 0;
}
