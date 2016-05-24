class DB
{
private:
    char book_[MAX_CHAR];
    char user_[User::numUsers][MAX_CHAR];;
public:
    DB();
    DB(book, user);
    ~DB();
}
