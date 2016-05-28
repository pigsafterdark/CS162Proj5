#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
#include "Book.h"
#include "User.h"
#include "LinkedList.h"
using namespace std;

char Menu();
void Menu2A();
char Menu2B();

void ReadUserFile();
void ReadBookFile();

void Login();
void Register();

void PrintBookList();
void UserBooks();
void CheckOut();
void CheckIn();

void PrintUserList();

LinkedList llUser, llBook;

char fullname[MAX_CHAR];

int main()
{
  //reads in the files
  ReadUserFile();
  ReadBookFile();

  bool terminate = false;
  char selection;

  while (!terminate)
    {
      selection = Menu();

      switch (selection)
        {
        case 'a':
	  Login();
          break;
        case 'b':
	  Register();
          break;
        case 'c':
	  terminate = true;
          break;
        default:
          cout << "That is not a valid choice!\n";
        }
    }
}

char Menu()
{
  cout << endl << "a)Login" << endl;
  cout << "b)Register" << endl;
  cout << "c)Quit" << endl;

  char selection;
  cin >> selection;
  return selection;
}

void Menu2A()
{
  bool terminate = false;
  char selection;

  while (!terminate)
    {
      selection = Menu2B();

      switch (selection)
        {
        case 'a':
	  PrintBookList();
          break;
        case 'b':
	  UserBooks();
          break;
        case 'c':
	  CheckOut();
          break;
        case 'd':
	  CheckIn();
          break;
        case 'e':
          terminate = true;
          break;
        default:
          cout << "That is not a valid choice!\n";
        }
    }
}

char Menu2B()
{
  cout << endl << "a)List all Books" << endl;
  cout << "b)Books I've checked out" << endl;
  cout << "c)Check out a book" << endl;
  cout << "d)Return a book" << endl;
  cout << "e)Logout" << endl;

  char selection;
  cin >> selection;
  return selection;
}

void ReadUserFile()
{
  ifstream in;
  int tempCounter = 0;
  char tempFName[MAX_CHAR], tempLName[MAX_CHAR];
  int tempNumChecked;

  //Count the number of lines in the input file
  in.open("users.txt");
    while (!in.eof())
      {
	in.ignore(10000, '\n');
	in.peek();
	tempCounter++;
      }
  in.close();
  in.clear(std::ios_base::goodbit);

  in.open("users.txt");

  //stores parsed lines into user object and linked list
  for (int i = 0; i < tempCounter; i++)
    {
      in.get(tempFName, MAX_CHAR, ';');
      in.ignore(MAX_CHAR, ';');
      in.get(tempLName, MAX_CHAR, ';');
      in.ignore(MAX_CHAR, ';');
      in >> tempNumChecked;
      in.ignore(MAX_CHAR, '\n');

      User * aUser = new User;
      aUser->setFName(tempFName);
      aUser->setLName(tempLName);
      aUser->setNumChecked(tempNumChecked);

      llUser.AddLinkToBack(aUser);

    }
  in.close();
  in.clear(std::ios_base::goodbit);
}

void ReadBookFile()
{
  ifstream in;
  int tempCounter = 0;
  char tempAuthor[MAX_CHAR], tempTitle[MAX_CHAR];
  int tempQuantity;

  //Count the number of lines in the input file                                                       
  in.open("books.txt");
  while (!in.eof())
    {
      in.ignore(10000, '\n');
      in.peek();
      tempCounter++;
    }
  in.close();
  in.clear(std::ios_base::goodbit);

  //stores parsed lines into book object and linked list                                              
  in.open("books.txt");
  for (int i = 0; i < tempCounter; i++)
    {
      in.get(tempTitle, MAX_CHAR, ';');
      in.ignore(MAX_CHAR, ';');
      in.get(tempAuthor, MAX_CHAR, ';');
      in.ignore(MAX_CHAR, ';');
      in >> tempQuantity;
      in.ignore(MAX_CHAR, '\n');
      
      Book * aBook = new Book;
      aBook->setTitle(tempTitle);
      aBook->setAuthor(tempAuthor);
      aBook->setQuantity(tempQuantity);

      llBook.AddLinkToBack(aBook);

    }
  in.close();
  in.clear(std::ios_base::goodbit);
}


void Login()
{
  //gets user input
  cout << "Enter your name to login: ";
  char listName[MAX_CHAR];
  cin.ignore();
  cin.get(fullname, MAX_CHAR, '\n');
  cin.ignore(MAX_CHAR, '\n');
  cout << endl;

  //see if user exists
  long counter = llUser.GetListLength();
  if (counter != 0)
    {
      User * aUser = (User*)(llUser.GetFirstNode());
      strcpy(listName, aUser->getName());
      if (strcmp(fullname, listName) == 0)
	{
	  cout << "Login Successful" << endl;
	  Menu2A();
	}
      for (int i = 0; i < (counter - 1); i++)
	{
	  aUser = (User*)(llUser.GetNextNode());
	  strcpy(listName, aUser->getName());
	  if (strcmp(fullname, listName) == 0)
	    {
	      cout << "Login Successful" << endl;
	      Menu2A();
	    }
	}
    }
  else
    {
      cout << "No user list" << endl;
    }
  cout << "No user found" << endl;
}

void Register()
{
  //gets user input for name
  char finput[MAX_CHAR], linput[MAX_CHAR], listName[MAX_CHAR], name[MAX_CHAR], templName[MAX_CHAR], tempfName[MAX_CHAR];
  cin.ignore();
  cout << "Enter your first name: ";
  cin >> finput;
  cin.ignore();
  cout << "Enter your last name: ";
  cin >> linput;
  
  //cats first name and last name
  char space[5] = " ";
  strcpy(tempfName, finput);
  strcpy(templName, linput);
  strcpy(name, strcat(tempfName, strcat(space, templName)));
 
  //see if user exists
  long counter = llUser.GetListLength();
  if (counter != 0)
    {
      User * aUser = (User*)(llUser.GetFirstNode());
      strcpy(listName, aUser->getName());
      if (strcmp(name, listName) == 0)
        {
          cout << "User exists" << listName << endl;
          return;
        }
      for (int i = 0; i < (counter - 1); i++)
        {
          aUser = (User*)(llUser.GetNextNode());
          strcpy(listName, aUser->getName());
          if (strcmp(name, listName) == 0)
            {
              cout << "User Exists" << listName << endl;
	      return;
            }
        }
    }
  else
    {
      cout << "No user list" << endl;
    }

  //stores name into obj and linked list
  User* userObj = new User;
  userObj->setFName(finput);
  userObj->setLName(linput);
  userObj->setNumChecked(0);
  llUser.AddLinkToBack(userObj);
  userObj->AppendToFile();

  cout << "Congrats, your username is now '" << name << "'!" << endl;
  Menu2A();
}

void PrintBookList()
{
  //prints book list                                                                                   
  long counter = llBook.GetListLength();

  if (counter != 0)
    {
      Book * aBook = (Book*)(llBook.GetFirstNode());
      aBook->PrintToConsole();
      for (int i = 0; i < (counter - 1); i++)
        {
          aBook = (Book*)(llBook.GetNextNode());
          aBook->PrintToConsole();
        }
    }
  else
    cout << "No list loaded" << endl;
}

void UserBooks()
{
  long counter = llBook.GetListLength();
 
  char bookName[MAX_CHAR];

  if (counter != 0)
    {
      Book * aBook = (Book*)(llBook.GetFirstNode());
      strcpy(bookName, aBook->userBooks(fullname));
	  if (strcmp(bookName, "empty") != 0)
	{
	  cout << bookName;
        }
      for (int i = 0; i < (counter - 1); i++)
	 {
	   aBook = (Book*)(llBook.GetNextNode());
	   strcpy(bookName, aBook->userBooks(fullname));
	   if (strcmp(bookName, "empty") != 0)
	     {
	       cout << bookName;
	     }
	 }
    }
}

void CheckOut()
{
  char binput[MAX_CHAR];
  cin.ignore();
  cout << "Enter the book you want to check out: ";
  cin.get(binput, MAX_CHAR, '\n');
  cin.ignore(MAX_CHAR, '\n');
  cout << endl;

  long counter = llBook.GetListLength();
  Book * aBook = (Book*)(llBook.GetFirstNode());
  if (strcmp(aBook->getTitle(), binput) == 0)
    {
      aBook->checkOut(fullname);
      return;
    }
  for (int i = 0; i < (counter - 1); i++)
    {
      aBook = (Book*)(llBook.GetNextNode());
		if (strcmp(aBook->getTitle(), binput) == 0)
	{
	  aBook->checkOut(fullname);
	  return;
	}
	 }

}

void CheckIn()
{
	char binput[MAX_CHAR];
	cin.ignore();
	cout << "Enter the book you want to check in: ";
	cin.get(binput, MAX_CHAR, '\n');
	cin.ignore(MAX_CHAR, '\n');
	cout << endl;

	long counter = llBook.GetListLength();
	Book * aBook = (Book*)(llBook.GetFirstNode());
	if (strcmp(aBook->getTitle(), binput) == 0)
	{
		aBook->checkIn(fullname);
		return;
	}
	for (int i = 0; i < (counter - 1); i++)
	{
		aBook = (Book*)(llBook.GetNextNode());
		if (strcmp(aBook->getTitle(), binput) == 0)
		{
			aBook->checkIn(fullname);
			return;
		}
	}
}


void PrintUserList()
{
  //prints user list
  long counter = llUser.GetListLength();

  if (counter != 0)
    {
      User * aUser = (User*)(llUser.GetFirstNode());
      aUser->PrintToConsole();
      for (int i = 0; i < (counter - 1); i++)
        {
          aUser = (User*)(llUser.GetNextNode());
          aUser->PrintToConsole();
        }
    }
  else
    cout << "No list loaded" << endl;
}


