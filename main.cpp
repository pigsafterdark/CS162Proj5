#include <iostream>
#include <string.h>
#include "Book.h"
#include "User.h"
#inlcude "DB.h"

using namespace std;

char Menu();
void Menu2A();
char Menu2B();

void Login();
void Register();

void ListBooks();

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
  cout << "b)" << endl;
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
  char input[256];
  cin.ignore();
  cin.get(input, 256, '\n');
  cin.ignore(256, '\n');
  cout << endl;

  
}

void Register()
{
  cout << "Enter your first name: ";
  char finput[256];
  cin >> finput;
  cout << "Enter your last name: ";
  char linput[256];
  cin << linput[256];
}
