#include <iostream>
#include <string.h>
#include "Book.h"
#include "User.h"
#inlcude "DB.h"

using namespace std;

char Menu();

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

char Menu()
{
  cout << endl << "a)" << endl;
  cout << "b)" << endl;
  cout << "c)" << endl;
  cout << "d)" << endl;
  cout << "e)" << endl;
  cout << "f)" << endl;

  char selection;
  cin >> selection;
  return selection;
}

