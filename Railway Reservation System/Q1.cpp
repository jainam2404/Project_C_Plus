#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

class Train
{
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[20];
    static int trainCount;

public:
    Train()
    {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
    }

    ~Train()
    {

        if (trainNumber != 0)
            trainCount--;
    }

    void inputTrainDetails()
    {

        cout << "Enter Train Number: ";
        while (!(cin >> trainNumber))
        {
            cout << "Invalid number. Enter Train Number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Train Name: ";
        cin.getline(trainName, sizeof(trainName));

        cout << "Enter Source: ";
        cin.getline(source, sizeof(source));

        cout << "Enter Destination: ";
        cin.getline(destination, sizeof(destination));

        cout << "Enter Train Time: ";
        cin.getline(trainTime, sizeof(trainTime));

        trainCount++;
    }

    void displayTrainDetails() const
    {
        cout << "Train Number: " << trainNumber << "\n"
             << "Train Name: " << trainName << "\n"
             << "Source: " << source << "\n"
             << "Destination: " << destination << "\n"
             << "Train Time: " << trainTime << "\n";
    }

    int getTrainNumber() const
    {
        return trainNumber;
    }

    static int getTrainCount()
    {
        return trainCount;
    }
};

// static member init
int Train::trainCount = 0;

class RailwaySystem
{
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem() : totalTrains(0) {}

    void addTrain()
    {
        if (totalTrains >= 100)
        {
            cout << "Train limit reached (100)." << endl;
            return;
        }
        cout << "\nAdding train #" << totalTrains + 1 << ":\n";
        trains[totalTrains].inputTrainDetails();
        totalTrains++;
    }

    void displayAllTrains()
    {
        if (totalTrains == 0)
        {
            cout << "No train records available!" << endl;
            return;
        }

        int i = 0;
        while (i < totalTrains)
        {
            cout << "\nTrain " << (i + 1) << " details:\n";
            trains[i].displayTrainDetails();
            i++;
        }
    }

    void searchTrainByNumber(int number)
    {
        int i = 0;
        bool found = false;
        while (i < totalTrains)
        {
            if (trains[i].getTrainNumber() == number)
            {
                cout << "\nTrain found:\n";
                trains[i].displayTrainDetails();
                found = true;
                break;
            }
            i++;
        }
        if (!found)
        {
            cout << "Train with number " << number << " not found!" << endl;
        }
    }

    void ensureMinimumTrains(int minRequired = 3)
    {
        cout << "\n(You should enter at least " << minRequired << " train records.)\n";
        while (totalTrains < minRequired)
        {
            cout << "\nEnter details for initial train #" << totalTrains + 1 << ":\n";
            addTrain();
        }
    }

    void menu()
    {
        while (true)
        {
            cout << "\n--- Railway Reservation System Menu ---\n"
                 << "1. Add New Train Record\n"
                 << "2. Display All Train Records\n"
                 << "3. Search Train by Number\n"
                 << "4. Exit\n"
                 << "Enter your choice: ";

            int choice;
            if (!(cin >> choice))
            {
                cout << "Invalid choice. Please enter a number (1-4)." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (choice)
            {
            case 1:
                addTrain();
                break;
            case 2:
                displayAllTrains();
                break;
            case 3:
            {
                cout << "Enter Train Number to search: ";
                int num;
                if (!(cin >> num))
                {
                    cout << "Invalid train number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else
                {
                    searchTrainByNumber(num);
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            case 4:
                cout << "Exiting the system. Goodbye!" << endl;
                return;
            default:
                cout << "Invalid choice! Try again." << endl;
                break;
            }
        }
    }
};

int main()
{
    RailwaySystem rs;
    rs.menu();
    return 0;
}
