#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Book.h"


using namespace std;

Book::Book()
{
	for (int i = 0; i < 15; i++)
	{
		userList_[i] = "Empty";
	}

	quantity_ = 0;
}

Book::~Book()
{
}

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

void Book::setTitle(char* title)
{
  strcpy(title_, title);
}

void Book::setAuthor(char* author)
{
  strcpy(author_, author);
}

void Book::setQuantity(int quantity)
{
  quantity_ = quantity;
}

void Book::PrintToConsole()
{
  cout << endl;
  cout << "Title: " << title_ << endl;
  cout << "Author: " << author_ << endl; 
  //cout << quantity_ << endl; should we print out how many there are?
}

void Book::AppendToFile()
{
  ofstream out;
  out.open("books.txt", ios::app);
  out << this->title_ << ";"
      << this->author_ << ";"
      << this->quantity_ << '\n';
  out.close();
}

void Book::checkOut(char* user)
{
  string tempUser(user);
  int x = 0;
  for(int i = 0; i < quantity_; i++)
    {
      if(userList_[i] == "Empty")
	{
	  userList_[i] = tempUser;
	  x = 1;
	}
      if(x == 1)
	{
	  break;
	}
    }
}

void Book::checkIn(char* user)
{
  string tempUser(user);
  for(int i = 0; i < quantity_; i++)
    {
      if(userList_[i] == tempUser)
        {
	  userList_[i] = "Empty";
        }
    }
}

char* Book::userBooks(char* user)
{
  string tempUser(user);
  for(int i = 0; i < 15; i++)
    {
      if(userList_[i] == tempUser)
        {
	  return title_;
        }
    }
  return "empty";
}



