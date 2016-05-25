#ifndef BOOK_H
#define BOOK_H
#define _CRT_SECURE_NO_WARNINGS

#include "User.h"

class Book
{
private:
    char title_[MAX_CHAR];
    char author_[MAX_CHAR];
    int quantity_;
public:
    static int numBooks;
    char* getTitle();
    char* getAuthor();
    int getQuantity();
    void setQuantity(int quantity);
    void PrintToConsole();
    void AppendToFile();
};

#endif
