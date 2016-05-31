#ifndef USER_H
#define USER_H
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
const int MAX_CHAR = 1000;

class User
{
 private:
  char fName_[MAX_CHAR];
  char lName_[MAX_CHAR];
  char Name_[MAX_CHAR];
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
  void setName(char* aName);
  int getNumChecked();
  void setNumChecked(int aNumber);
  void PrintToConsole();
  void AppendToFile();
};

#endif
