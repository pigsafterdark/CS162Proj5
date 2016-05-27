#ifndef USER_H
#define USER_H
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
const int MAX_CHAR = 100;

class User
{
 private:
  char fName_[MAX_CHAR];
  char lName_[MAX_CHAR];
  int numChecked_;
 public: 
  User();
  ~User();
  static int numUsers;
  char* getFName();
  void setFName(char* aName);
  char* getLName();
  void setLName(char* aName);
  char* getName();
  int getNumChecked();
  void setNumChecked(int aNumber);
  void PrintToConsole();
  void AppendToFile();
};

#endif
