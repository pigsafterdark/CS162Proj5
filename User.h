#define _CRT_SECURE_NO_WARNINGS

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
  
int User::getNumChecked()
{
      return numChecked_;
}
 
void User::setNumChecked(int aNumber)
{
      numChecked_ = aNumber;
}

