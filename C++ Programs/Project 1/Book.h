#include <string>
using namespace std;

class Book
{
public:
    Book();
    Book(string n, string a);
    Book(string n, string a, short y);

    string getName() { return bname; }
    string getAuthor() { return author; }
    short getYear() { return year; }

    void setName(string n) { bname = n; }
    void setAuthor(string a) { author = a; }
    void setYear(int y) { year = y; }

    void toString();

private:
    string bname;
    string author;
    unsigned short year;
};
