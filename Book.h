class Book
{
private:
    char title_[MAX_CHAR];
    char author_[MAX_CHAR];
    int quantity_;
public:
    static int numBooks;
    char getTitle();
    char getAuthor();
    int getQuantity();
    void setQuantity(quantity);
}
