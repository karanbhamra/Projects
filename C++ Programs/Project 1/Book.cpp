#include <iostream>
#include <Book.h>

using std::cout;
using std::endl;

Book::Book() {}

Book::Book(string n, string a)
{
    bname = n;
    author = a;
}

Book::Book(string n, string a, short y)
{
    bname = n;
    author = a;
    year = y;
}

void Book::toString()
{
    cout << "The Book object is: " << this->getName() << ", " << this->getAuthor() << ", " << this->getYear() << "." << endl;
}
