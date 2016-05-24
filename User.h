Class User
{
  Private:
    char fName_[MAX_CHAR];
    char lName_[MAX_CHAR];
    int numChecked_;
 Public: 
    static int numUsers;
    char getFName();
    void setFName(char* aName);
    char getLName();
    void setLName(char* aName);
    int getnumChecked();
    void setnumChecked(numChecked);
}
