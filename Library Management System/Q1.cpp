#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 100;

class LibraryItem
{
protected:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(string t, string a) : title(t), author(a), dueDate("None") {}

    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getDueDate() { return dueDate; }

    void setDueDate(string date) { dueDate = date; }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    virtual ~LibraryItem() {}
};

class Book : public LibraryItem
{
public:
    Book(string t, string a) : LibraryItem(t, a) {}

    void checkOut() override
    {
        cout << "Enter due date for book: ";
        cin >> dueDate;
        cout << "Book checked out.\n";
    }

    void returnItem() override
    {
        dueDate = "None";
        cout << "Book returned.\n";
    }

    void displayDetails() override
    {
        cout << "Book - Title: " << title << "\n"
             << "- Author: " << author << "\n"
             << "- Due Date: " << dueDate << endl;
    }
};

class DVD : public LibraryItem
{
public:
    DVD(string t, string a) : LibraryItem(t, a) {}

    void checkOut() override
    {
        cout << "Enter due date for DVD: ";
        cin >> dueDate;
        cout << "DVD checked out.\n";
    }

    void returnItem() override
    {
        dueDate = "None";
        cout << "DVD returned.\n";
    }

    void displayDetails() override
    {
        cout << "DVD - Title: " << title << "\n"
             << "- Director: " << author << "\n"
             << "- Due Date: " << dueDate << endl;
    }
};

class Magazine : public LibraryItem
{
public:
    Magazine(string t, string a) : LibraryItem(t, a) {}

    void checkOut() override
    {
        cout << "Enter due date for magazine: ";
        cin >> dueDate;
        cout << "Magazine checked out.\n";
    }

    void returnItem() override
    {
        dueDate = "None";
        cout << "Magazine returned.\n";
    }

    void displayDetails() override
    {
        cout << "Magazine - Title: " << title << "\n"
             << "- Editor: " << author<< "\n"
             << "- Due Date: " << dueDate << endl;
    }
};

int main()
{
    LibraryItem *items[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    do
    {
        cout << "\n=== Library Menu ===\n";
        cout << "1. Add Book\n2. Add DVD\n3. Add Magazine\n";
        cout << "4. Display All Items\n5. Check Out Item\n6. Return Item\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2 || choice == 3)
        {
            if (itemCount >= MAX_ITEMS)
            {
                cout << "Library is full!\n";
                continue;
            }

            string title, author;
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author/director/editor: ";
            getline(cin, author);

            if (choice == 1)
                items[itemCount++] = new Book(title, author);
            else if (choice == 2)
                items[itemCount++] = new DVD(title, author);
            else
                items[itemCount++] = new Magazine(title, author);

            cout << "Item added successfully.\n";
        }
        else if (choice == 4)
        {
            for (int i = 0; i < itemCount; i++)
            {
                cout << "[" << i << "] ";
                items[i]->displayDetails();
            }
        }
        else if (choice == 5)
        {
            int index;
            cout << "Enter item number to check out: ";
            cin >> index;
            if (index >= 0 && index < itemCount)
                items[index]->checkOut();
            else
                cout << "Invalid item number.\n";
        }
        else if (choice == 6)
        {
            int index;
            cout << "Enter item number to return: ";
            cin >> index;
            if (index >= 0 && index < itemCount)
                items[index]->returnItem();
            else
                cout << "Invalid item number.\n";
        }
        else if (choice == 0)
        {
            cout << "Exiting the system. Goodbye!\n";
        }
        else
        {
            cout << "Invalid option.\n";
        }

    } while (choice != 0);

    for (int i = 0; i < itemCount; i++)
    {
        delete items[i];
    }

    return 0;
}
