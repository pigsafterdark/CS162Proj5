 //this is User.cpp
  2 #include "User.h"
  3
  4 int numUsers = 0;
  5
  6 User::User()
  7 {
  8     numChecked_ = 0;
  9 }
 10
 11 User::~User()
 12 {
 13
 14 }
 15
 16 char User::getName()
 17 {
 18     return name_;
 19 }
 20
 21 void User::setName(char * aName)
 22 {
 23     strcpy(name_, aName);
 24 }
 25
 26 int User::getNumChecked()
 27 {
 28     return numChecked_;
 29 }
 30
 31 void User::setNumChecked(aNumber)
 32 {
 33     numChecked_ = aNumber;
 34 }
