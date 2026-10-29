#include "LinkedList.h"
#include "CreateBook.h"
#include <iostream>
#include <utility>
using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
}

BookNode* LinkedList::GetNodeAt(int index) {
    if (index < 0)
        return nullptr;

    BookNode* current = head;

    for (int i = 0; current != nullptr && i < index; i++) {
        current = current->next;
    }

    return current;
}

void LinkedList::CopyBookData(BookNode* first, BookNode* second) {
    if (first != nullptr && second != nullptr) {
        swap(first->bookID, second->bookID);
        swap(first->title, second->title);
    }
}

void LinkedList::Insert(int id, string title) {
    BookNode* newBook = CreateBook(id, title);
    newBook->next = head;
    head = newBook;
}

void LinkedList::Remove() {
    if (IsEmpty()) {
        cout << "Collection is empty.\n";
        return;
    }

    BookNode* temp = head;
    head = head->next;
    delete temp;

    cout << "Book removed from head.\n";
}

bool LinkedList::IsEmpty() {
    return head == nullptr;
}

bool LinkedList::IsNotEmpty() {
    return head != nullptr;
}

void LinkedList::InsertAt(int index, int id, string title) {
    if (index < 0) {
        cout << "Invalid index.\n";
        return;
    }

    if (index == 0) {
        Insert(id, title);
        return;
    }

    BookNode* previous = GetNodeAt(index - 1);

    if (previous == nullptr) {
        cout << "Index out of range.\n";
        return;
    }

    BookNode* newBook = CreateBook(id, title);
    newBook->next = previous->next;
    previous->next = newBook;

    cout << "Book inserted successfully.\n";
}

void LinkedList::RemoveAt(int index) {
    if (index < 0 || IsEmpty()) {
        cout << "Invalid index or empty collection.\n";
        return;
    }

    if (index == 0) {
        Remove();
        return;
    }

    BookNode* previous = GetNodeAt(index - 1);

    if (previous == nullptr || previous->next == nullptr) {
        cout << "Index out of range.\n";
        return;
    }

    BookNode* temp = previous->next;
    previous->next = temp->next;
    delete temp;

    cout << "Book removed successfully.\n";
}

void LinkedList::Swap(int index1, int index2) {
    BookNode* first = GetNodeAt(index1);
    BookNode* second = GetNodeAt(index2);

    if (first == nullptr || second == nullptr) {
        cout << "Invalid index.\n";
        return;
    }

    CopyBookData(first, second);
    cout << "Books swapped successfully.\n";
}

void LinkedList::Sort() {
    for (BookNode* i = head; i != nullptr; i = i->next) {
        for (BookNode* j = i->next; j != nullptr; j = j->next) {
            if (i->bookID > j->bookID) {
                CopyBookData(i, j);
            }
        }
    }

    cout << "Books sorted by ID.\n";
}

void LinkedList::Reverse() {
    BookNode* previous = nullptr;
    BookNode* current = head;

    while (current != nullptr) {
        BookNode* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    head = previous;
    cout << "Collection reversed.\n";
}

void LinkedList::Print() {
    if (IsEmpty()) {
        cout << "No books in collection.\n";
        return;
    }

    BookNode* current = head;

    while (current != nullptr) {
        cout << "Book ID: " << current->bookID
             << " | Title: " << current->title << '\n';

        current = current->next;
    }
}

LinkedList::LinkedList(const LinkedList& other) {
    head = nullptr;

    BookNode* current = other.head;

    while (current != nullptr) {
        InsertAt(0, current->bookID, current->title);
        current = current->next;
    }

    Reverse();
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this == &other)
        return *this;

    while (head != nullptr) {
        BookNode* temp = head;
        head = head->next;
        delete temp;
    }

    BookNode* current = other.head;

    while (current != nullptr) {
        InsertAt(0, current->bookID, current->title);
        current = current->next;
    }

    Reverse();
    return *this;
}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        BookNode* temp = head;
        head = head->next;
        delete temp;
    }
}