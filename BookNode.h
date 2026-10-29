#ifndef BOOKNODE_H
#define BOOKNODE_H

#include <string>
using namespace std;

struct BookNode {
    int bookID;
    string title;
    BookNode* next;
};

#endif