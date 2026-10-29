#include <iostream>
#include <limits>
#include <string>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList books;

    // Initial books
    books.Insert(103, "Database Systems");
    books.Insert(101, "Programming Fundamentals");
    books.Insert(102, "Data Structures");

    int choice;

    do {
        cout << "\n===== Library Book Collection =====\n";
        cout << "1. Display All Books\n";
        cout << "2. Insert Book at Head\n";
        cout << "3. Remove Book from Head\n";
        cout << "4. Insert Book at Index\n";
        cout << "5. Remove Book at Index\n";
        cout << "6. Swap Books\n";
        cout << "7. Sort Books by ID\n";
        cout << "8. Reverse Book Collection\n";
        cout << "9. Check Collection Status\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Please enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        int id, index, index1, index2;
        string title;

        switch (choice) {
        case 1:
            books.Print();
            break;

        case 2:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Book Title: ";
            getline(cin, title);

            books.Insert(id, title);
            cout << "Book inserted at head.\n";
            break;

        case 3:
            books.Remove();
            break;

        case 4:
            cout << "Enter index (starting from 0): ";
            cin >> index;

            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Book Title: ";
            getline(cin, title);

            books.InsertAt(index, id, title);
            break;

        case 5:
            cout << "Enter index to remove: ";
            cin >> index;
            books.RemoveAt(index);
            break;

        case 6:
            cout << "Enter first index: ";
            cin >> index1;

            cout << "Enter second index: ";
            cin >> index2;

            books.Swap(index1, index2);
            break;

        case 7:
            books.Sort();
            break;

        case 8:
            books.Reverse();
            break;

        case 9:
            if (books.IsEmpty())
                cout << "Collection is empty.\n";
            else
                cout << "Collection contains books.\n";
            break;

        case 10:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 10);

    return 0;
}
