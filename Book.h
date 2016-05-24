Class Book
{
Private:
    Char title_[MAX_CHAR];
    char author_[MAX_CHAR];
    Int quantity_;
Public:
    Static int numBooks;
    Char getTitle();
    Char getAuthor();
    Int quantity();
    Void setQuantity(quantity);
}
