
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
     return lName;
 }
 
 void User::SetLName(char* aName)
 {
     strcpy(lName_, aName);
 }
  
int User::getNumChecked()
{
      return numChecked_;
}
 
  void User::setNumChecked(aNumber)
{
      numChecked_ = aNumber;
}
