#include <iostream>
#include <string>
using namespace std;

class Train {
    int number;
    string name, source, destination, time;

public:
    void input() {
        cout << "\nEnter Train Number: ";
        cin >> number;
        cin.ignore();
        cout << "Enter Train Name: ";
        getline(cin, name);
        cout << "Enter Source: ";
        getline(cin, source);
        cout << "Enter Destination: ";
        getline(cin, destination);
        cout << "Enter Train Time: ";
        getline(cin, time);
    }

    void display() const {
        cout << "\nTrain Number: " << number
             << "\nTrain Name: " << name
             << "\nSource: " << source
             << "\nDestination: " << destination
             << "\nTrain Time: " << time << endl;
    }

    int getNumber() const { return number; }
};

class RailwaySystem {
    Train trains[100];
    int count = 0;

public:
    void addTrain() {
        if (count >= 100) {
            cout << "Train limit reached!" << endl;
            return;
        }
        cout << "\n--- Add New Train ---";
        trains[count].input();
        count++;
        cout << "Train added successfully!\n";
    }

    void displayAll() const {
        if (count == 0) {
            cout << "No train records available!" << endl;
            return;
        }
        cout << "\n--- All Train Details ---";
        for (int i = 0; i < count; i++) {
            cout << "\nTrain #" << i + 1;
            trains[i].display();
        }
    }

    void searchTrain() const {
        if (count == 0) {
            cout << "No trains to search!" << endl;
            return;
        }
        int num;
        cout << "Enter Train Number to search: ";
        cin >> num;
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (trains[i].getNumber() == num) {
                cout << "\nTrain Found:";
                trains[i].display();
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Train not found!" << endl;
    }

    void menu() {
        int choice;
        do {
            cout << "\n--- Railway System Menu ---\n";
            cout << "1. Add Train\n2. Display All Trains\n3. Search Train\n4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: addTrain(); break;
                case 2: displayAll(); break;
                case 3: searchTrain(); break;
                case 4: cout << "Exiting...!!"; break;
                default: cout << "Invalid choice! Try again.\n"; break;
            }
        } while (choice != 4);
    }
};

int main() {
    RailwaySystem rs;
    rs.menu();
    return 0;
}
