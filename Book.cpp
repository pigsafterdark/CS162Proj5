#include <iostream>
#include "Book.h"

using namespace std;

char Book::getTitle()
{
  return title_;
}

char Book::getAuthor()
{
  return author_;
}

char Book::getQuantity()
{
  return quantity_;
}

void Book::setQuantity(quantity)
{
  quantity_ = quantity;
}
