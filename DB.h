Class DB
{
Private:
    Char book_[MAX_CHAR];
    char user_[User::numUsers][MAX_CHAR];;
Public:
    DB();
    DB(book, user);
    ~DB();
}
