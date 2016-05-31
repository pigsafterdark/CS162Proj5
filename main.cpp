#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include "Book.h"
#include "User.h"
#include "LinkedList.h"
using namespace std;

char Menu();
void Menu2A();
char Menu2B();
void Menu3A();
char Menu3B();

void ReadUserFile();
void ReadBookFile();

void Login();
void Register();

void SearchTitle();
void SearchAuthor();
void SearchType();
void PrintBookList();
void UserBooks();
void CheckOut();
void CheckIn();
void LogOut();

void PrintUserList();

LinkedList llUser, llBook;

char fullname[MAX_CHAR];
int numbooks, numusers;

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
      
      switch(selection)
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
	  Menu3A();
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
	  LogOut();
          break;
        default:
          cout << "That is not a valid choice!\n";
        }
    }
}

char Menu2B()
{
  cout << endl << "a)Search for a book" << endl;
  cout << "b)Books I've checked out" << endl;
  cout << "c)Check out a book" << endl;
  cout << "d)Return a book" << endl;
  cout << "e)Logout" << endl;

  char selection;
  cin >> selection;
  return selection;
}
void Menu3A()
{
  bool terminate = false;
  char selection;

  while (!terminate)
    {
      selection = Menu3B();

      switch (selection)
        {
        case 'a':
          PrintBookList();
          break;
        case 'b':
	  SearchTitle();
          break;
        case 'c':
	  SearchAuthor();
          break;
        case 'd':
	  SearchType();
          break;
        case 'e':
          Menu2A();
          break;
        default:
          cout << "That is not a valid choice!\n";
        }
    }
}

char Menu3B()
{
  cout << endl << "a)List All Books" << endl;
  cout << "Search By:" << endl;
  cout << "    b)Title" << endl;
  cout << "    c)Author" << endl;
  cout << "    d)Category" << endl;
  cout << "e)Return" << endl;

  char selection;
  cin >> selection;
  return selection;
}

void ReadUserFile()
{
  ifstream in;
  int tempCounter = 0;
  char tempFName[MAX_CHAR], tempLName[MAX_CHAR], tempName[MAX_CHAR];
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
      
      strcpy(tempName, tempFName);
      strcat(tempName, " ");
      strcat(tempName, tempLName);

      User * aUser = new User;
      aUser->setFName(tempFName);
      aUser->setLName(tempLName);
      aUser->setName(tempName);
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
  char tempAuthor[MAX_CHAR], tempTitle[MAX_CHAR], qint[MAX_CHAR], tempType[MAX_CHAR];
  int tempQuantity, x;
  string users[MAX_CHAR] = "Empty";

  //Count the number of lines in the input file                                                       
  in.open("books.txt");
  while (!in.eof())
    {
      in.ignore(10000, '\n');
      in.peek();
      tempCounter++;
      numbooks++;
    }
  in.close();
  in.clear(std::ios_base::goodbit);

  //stores parsed lines into book object and linked list                                              
  in.open("books.txt");
  for (int i = 0; i < tempCounter; i++)
    {
      Book * aBook = new Book;
      in.get(tempTitle, MAX_CHAR, ';');
      in.ignore(MAX_CHAR, ';');
      in.get(tempAuthor, MAX_CHAR, ';');
      in.ignore(MAX_CHAR, ';');
      in.get(qint, MAX_CHAR, ';');
      in.ignore(MAX_CHAR, ';');
      tempQuantity = atoi(qint);
      in.get(tempType, MAX_CHAR, ';');
      in.ignore(MAX_CHAR, ';');

      aBook->setQuantity(tempQuantity);
      aBook->setTitle(tempTitle);
      aBook->setAuthor(tempAuthor);
      aBook->setType(tempType);

      for(x = 0; x < tempQuantity; x++)
	{
	  getline(in, users[x], ';');
	}
      in.ignore(MAX_CHAR, '\n');
      for(x = 0; x < tempQuantity; x++)
	{
	  aBook->setUsers(users[x]);
	}
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
  userObj->setName(name);
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
      if (strcmp(bookName, "Empty") != 0)
	{
	  cout << bookName << endl;
        }
      for (int i = 0; i < (counter - 1); i++)
	 {
	   aBook = (Book*)(llBook.GetNextNode());
	   strcpy(bookName, aBook->userBooks(fullname));
	   if (strcmp(bookName, "Empty") != 0)
	     {
	       cout << bookName << endl;
	     }
	 }
    }
  //cout << "You do not have any books currently checked out" << endl;
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

      ofstream out;
      out.open("books.txt");
      out.close();

      long counter = llBook.GetListLength();
      Book * aBook = (Book*)(llBook.GetFirstNode());
      aBook->AppendToFile();
      for(int i = 0; i < (counter - 1); i++)
	{
	  aBook = (Book*)(llBook.GetNextNode());
	  aBook->AppendToFile();
	}

      cout << "Successfully checked out the book!" << endl;
      return;
    }
  for (int i = 0; i < (counter - 1); i++)
    {
      aBook = (Book*)(llBook.GetNextNode());
      if (strcmp(aBook->getTitle(), binput) == 0)
	{
	  aBook->checkOut(fullname);

	  ofstream out;
	  out.open("books.txt");
	  out.close();

	  long counterb = llBook.GetListLength();
	  Book * aBook = (Book*)(llBook.GetFirstNode());
	  aBook->AppendToFile();
	  for(int j = 0; j < (counterb - 1); j++)
	    {
	      aBook = (Book*)(llBook.GetNextNode());
	      aBook->AppendToFile();
	    }

	  cout << "Successfully checked out the book!" << endl;
	  return;
	}
    }
  cout << "Did not find the book you were looking for" << endl;
}

void CheckIn()
{
	char binput[MAX_CHAR];
	cin.ignore();
	cout << "Enter the book you want to return: ";
	cin.get(binput, MAX_CHAR, '\n');
	cin.ignore(MAX_CHAR, '\n');
	cout << endl;

	long counter = llBook.GetListLength();
	Book * aBook = (Book*)(llBook.GetFirstNode());
	if (strcmp(aBook->getTitle(), binput) == 0)
	{
		aBook->checkIn(fullname);

		ofstream out;
		out.open("books.txt");
		out.close();

		long counterb = llBook.GetListLength();
		Book * aBook = (Book*)(llBook.GetFirstNode());
		aBook->AppendToFile();
		for(int j = 0; j < (counterb - 1); j++)
		  {
		    aBook = (Book*)(llBook.GetNextNode());
		    aBook->AppendToFile();
		  }
		cout << "Successfully returned book." << endl;
		return;
	}
	for (int i = 0; i < (counter - 1); i++)
	{
		aBook = (Book*)(llBook.GetNextNode());
		if (strcmp(aBook->getTitle(), binput) == 0)
		{
			aBook->checkIn(fullname);

			ofstream out;
			out.open("books.txt");
			out.close();

			long counterb = llBook.GetListLength();
			Book * aBook = (Book*)(llBook.GetFirstNode());
			aBook->AppendToFile();
			for(int j = 0; j < (counterb - 1); j++)
			  {
			    aBook = (Book*)(llBook.GetNextNode());
			    aBook->AppendToFile();
			  }
			cout << "Successfully returned book." << endl;
			return;
		}
	}
	cout << "Did not find the book you wanted to return." << endl;
}

void LogOut()
{
  main();
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

void SearchTitle()
{
  char binput[MAX_CHAR];
  cin.ignore();
  cout << "Enter the title you want to search for: ";
  cin.get(binput, MAX_CHAR, '\n');
  cin.ignore(MAX_CHAR, '\n');
  cout << endl;

  long counter = llBook.GetListLength();
  Book * aBook = (Book*)(llBook.GetFirstNode());
  if (strcmp(aBook->getTitle(), binput) == 0)
    {
      cout << "Book found" << endl;
      cout << "Would you like to check this book out?" << endl;
      cout << "  a)yes" << endl;
      cout << "  b)no" << endl;
      char cinput[MAX_CHAR];
      cin.get(cinput, MAX_CHAR, '\n');
      cin.ignore(MAX_CHAR, '\n');
      if(strcmp(cinput, "a") == 0)
	{
	  aBook->checkOut(fullname);

	  ofstream out;
	  out.open("books.txt");
	  out.close();

	  long counterb = llBook.GetListLength();
	  Book * aBook = (Book*)(llBook.GetFirstNode());
	  aBook->AppendToFile();
	  for(int j = 0; j < (counterb - 1); j++)
	    {
	      aBook = (Book*)(llBook.GetNextNode());
	      aBook->AppendToFile();
	    }
	  cout << "Successfully checked out book";
            }
      if(strcmp(cinput, "b") == 0)
	{
	  return;
	}
    }
  for (int i = 0; i < (counter - 1); i++)
    {
      aBook = (Book*)(llBook.GetNextNode());
      if (strcmp(aBook->getTitle(), binput) == 0)
	{
	  cout << "Book found" << endl;
	  cout << "Would you like to check this book out?" << endl;
	  cout << "  a)yes" << endl;
	  cout << "  b)no" << endl;
	  char cinput[MAX_CHAR];
	  cin.get(cinput, MAX_CHAR, '\n');
	  cin.ignore(MAX_CHAR, '\n');
	  if(strcmp(cinput, "a") == 0)
	    {
	      aBook->checkOut(fullname);

	      ofstream out;
	      out.open("books.txt");
	      out.close();

	      long counterb = llBook.GetListLength();
	      Book * aBook = (Book*)(llBook.GetFirstNode());
	      aBook->AppendToFile();
	      for(int j = 0; j < (counterb - 1); j++)
		{
		  aBook = (Book*)(llBook.GetNextNode());
		  aBook->AppendToFile();
		}
	      cout << "Successfully checked out book";
	    }
	  if(strcmp(cinput, "b") == 0)
	    {
	      return;
	    }
	}
    }
  cout << "Did not find the book you wanted to checkout" << endl;
}

void SearchAuthor()
{
  char binput[MAX_CHAR];
  cin.ignore();
  cout << "Enter the Author you want to search for: ";
  cin.get(binput, MAX_CHAR, '\n');
  cin.ignore(MAX_CHAR, '\n');
  cout << endl;
  int e = 0;

  long counter = llBook.GetListLength();
  Book * aBook = (Book*)(llBook.GetFirstNode());
  if (strcmp(aBook->getAuthor(), binput) == 0)
    {
      e++;
      cout << aBook->getTitle() << endl;
    }
  for (int i = 0; i < (counter - 1); i++)
    {
      aBook = (Book*)(llBook.GetNextNode());
      if (strcmp(aBook->getAuthor(), binput) == 0)
        {
	  e++;
	  cout << aBook->getTitle() << endl;
        }
    }
  if(e != 0)
    {
      cout << "Would you like to check one of these books out?" << endl;
      cout << "  a)yes" << endl;
      cout << "  b)no" << endl;
      char cinput[MAX_CHAR];
      cin.get(cinput, MAX_CHAR, '\n');
      cin.ignore(MAX_CHAR, '\n');
      if(strcmp(cinput, "a") == 0)
	{
	  CheckOut();
	}
      if(strcmp(cinput, "b") == 0)
	{
	  return;
	}

    }
  else
    {
      cout << "Did not find the author you were looking for" << endl;
    }
}

void SearchType()
{
  char binput[MAX_CHAR];
  cin.ignore();
  cout << "Available Categories:" << endl;
  cout << "  Horror" << endl;
  cout << "  Comedy" << endl;
  cout << "  Romance" << endl;
  cout << "  Science Fiction" << endl;
  cout << "  Non Fiction" << endl;
  cout << "  Fiction" << endl;

  cout << "Enter the Category you want to search for: ";
  cin.get(binput, MAX_CHAR, '\n');
  cin.ignore(MAX_CHAR, '\n');
  cout << endl;
  int e = 0;

  long counter = llBook.GetListLength();
  Book * aBook = (Book*)(llBook.GetFirstNode());
  if (strcmp(aBook->getType(), binput) == 0)
    {
      e++;
      cout << aBook->getTitle() << endl;
    }
  for (int i = 0; i < (counter - 1); i++)
    {
      aBook = (Book*)(llBook.GetNextNode());
      if (strcmp(aBook->getType(), binput) == 0)
        {
          e++;
          cout << aBook->getTitle() << endl;
        }
    }
  if(e != 0)
    {
      cout << "Would you like to check one of these books out?" << endl;
      cout << "  a)yes" << endl;
      cout << "  b)no" << endl;
      string sinput;
      cin >> sinput;
      if(sinput == "a")
        {
          CheckOut();
        }
      if(sinput == "b")
        {
          Menu2A();
	}

    }
  else
    {
      cout << "Did not find the category you were looking for" << endl;
    }
}
