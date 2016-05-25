#include <iostream>
#include <string.h>
#include "Book.h"
#include "User.h"
//#include "DB.h"
#include "LinkedList.h"
using namespace std;

char Menu();
void Menu2A();
char Menu2B();

void Login();
void Register();

void ListBooks();

LinkedList llUser, llBook, llDB;

int main()
{
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
	  ListBooks();
          break;
        case 'b':
          break;
        case 'c':
          break;
        case 'd':
          break;
        case 'e':
          break;
        case 'f':
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
  cout << "c)" << endl;
  cout << "" << endl;
  cout << "" << endl;

  char selection;
  cin >> selection;
  return selection;
}

void Login()
{
  cout << "Enter your name to login: ";
  char input[256], listName[256];
  cin.ignore();
  cin.get(input, 256, '\n');
  cin.ignore(256, '\n');
  cout << endl;
  //see if user exists
  long counter = llUser.GetListLength();
  if (counter != 0)
    {
      User * aUser = (User*)(llUser.GetFirstNode());
      strcpy(listName, aUser->getName());
      if (strcmp(input, listName) == 0)
	{
	  cout << "User exists" << listName << endl;
	  return;
	}
      for (int i = 0; i < (counter - 1); i++)
	{
	  aUser = (User*)(llUser.GetNextNode());
	  strcpy(listName, aUser->getName());
	  if (strcmp(input, listName) == 0)
	    {
	      cout << "User Exists" << listName << endl;
	    }
	}
    }
  else
    cout << "No list loaded" << endl;
}

void Register()
{
  cin.ignore();
  cout << "Enter your first name: ";
  char finput[256];
  cin >> finput;
  cin.ignore();
  cout << "Enter your last name: ";
  char linput[256];
  cin >> linput;
  
  //see if user exists

  User* userObj;
  userObj->setFName(finput);
  userObj->setLName(linput);

  llUser.AddLinkToBack(userObj);

  cout << "Congrats, your username is now " << finput << " " << linput << "!" << endl;

  Menu2A();
}
