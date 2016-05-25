#include <iostream>
#include "Book.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

char* Book::getTitle()
{
  return title_;
}

char* Book::getAuthor()
{
  return author_;
}

int Book::getQuantity()
{
  return quantity_;
}

void Book::setQuantity(int quantity)
{
  quantity_ = quantity;
}
