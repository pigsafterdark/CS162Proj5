#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;

#include "User.h"
  
int numUsers = 0;
  
User::User()
{
  numChecked_ = 0;
}
 

User::~User()
{
  
}


char* User::getFName()
{
  return fName_;
}

void User::setFName(char * aName)
{
  strcpy(fName_, aName);
}
 
char* User::getLName()
{
  return lName_;
}
 
void User::setLName(char* aName)
{
  strcpy(lName_, aName);
}
 
char* User::getName()
{
  return Name_;
}

void User::setName(char* aName)
{
  strcpy(Name_, aName);
}
  
int User::getNumChecked()
{
  return numChecked_;
}
 
void User::setNumChecked(int aNumber)
{
  numChecked_ = aNumber;
}

void User::PrintToConsole()
{
  cout << fName_ << " " << lName_ << " "  << numChecked_ << endl;
}

void User::AppendToFile()
{
  ofstream out;
  out.open("users.txt", ios::app);
  out << this->fName_ << ";"
      << this->lName_ << ";"
      << this->numChecked_ << '\n';
  out.close();
}
