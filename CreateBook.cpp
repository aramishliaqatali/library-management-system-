#include "CreateBook.h"

BookNode* CreateBook(int id, string title) {
    BookNode* newBook = new BookNode;

    newBook->bookID = id;
    newBook->title = title;
    newBook->next = nullptr;

    return newBook;
}