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

void User::PrintToConsole()
{
	cout << endl << "Title: " << title_ << endl;
	cout << "Author: "author_ << endl <<; 
	//cout << quantity_ << endl; should we print out how many there are?
}

void User::AppendToFile()
{
	ofstream out;
	out.open("books.txt", ios::app);
	out << this->title_ << ";"
		<< this->author_ << ";"
		<< this->quantity_ << '\n';
	out.close();
}
