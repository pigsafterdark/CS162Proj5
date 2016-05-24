
#include <iostream>
#include <string.h>
#include "DB.h"

using namespace std;

DB::DB()
{
}

DB::DB(book, user)
{
  strcpy(book_, book);
  strcpy(user_, user);
}

DB::~DB()
{
}
