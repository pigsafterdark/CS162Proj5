#ifndef BOOK_H
#define BOOK_H
#define _CRT_SECURE_NO_WARNINGS

#include "User.h"

using namespace std;

class Book
{
  private: 
    char title_[MAX_CHAR];
    char author_[MAX_CHAR];
    int quantity_; 
    string userList_[15];
  public:
    static int numBooks;
    Book();
    ~Book();
    char* getTitle();
    char* getAuthor();
    int getQuantity();
    void setTitle(char* title);
    void setAuthor(char* title);
    void setQuantity(int quantity);
    void checkOut(char* user);
    void checkIn(char* user);
    char* userBooks(char* user);

    void PrintToConsole();
    void AppendToFile();
};

#endif
