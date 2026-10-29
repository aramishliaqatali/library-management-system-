#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "BookNode.h"
#include <string>
using namespace std;

class LinkedList {
private:
    BookNode* head;

    BookNode* GetNodeAt(int index);
    void CopyBookData(BookNode* first, BookNode* second);

public:
    LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);
    ~LinkedList();

    void Insert(int id, string title);
    void Remove();
    bool IsEmpty();
    bool IsNotEmpty();
    void InsertAt(int index, int id, string title);
    void RemoveAt(int index);
    void Swap(int index1, int index2);
    void Sort();
    void Reverse();
    void Print();
};

#endif