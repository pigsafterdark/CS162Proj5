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
 
 char* User::getName()
 {
   char tempfName[100], templName[100];
   strcpy(tempfName, fName_);
   strcpy(templName, lName_);
   return strcat(tempfName,strcat(" ", templName));
 }
  
int User::getNumChecked()
{
      return numChecked_;
}
 
void User::setNumChecked(int aNumber)
{
      numChecked_ = aNumber;
}
